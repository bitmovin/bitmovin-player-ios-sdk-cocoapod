import { BufferType, MediaType, PlayerEventV8, ViewMode, WarningCode } from './PlayerV8Enums';
import { EventEnumMapper } from './EventEnumMapper';
import {
  AudioQuality, AudioTrack, BufferLevel, DownloadedAudioData, DownloadedVideoData, LogLevel, LowLatencyAPI,
  MetadataType, PlayerAdvertisingAPI, PlayerAPI as PlayerAPIv8, PlayerBufferAPI, PlayerConfig, PlayerEvent,
  PlayerEventCallback, PlayerExports, PlayerSubtitlesAPI, PlayerType, PlayerVRAPI, QueryParameters,
  SegmentMap, Snapshot, SourceConfig, StreamType, SubtitleTrack, SupportedTechnologyMode, Technology, Thumbnail,
  TimeRange, VideoQuality, ViewModeOptions,
} from 'bitmovin-player-v8';
import { Logger } from '../helper/Logger';
import { NativePlayerStateHandler } from '../NativePlayerStateHandler';
import PlayerAPIv7 = bitmovin.PlayerAPI;
import Subtitle = bitmovin.PlayerAPI.Subtitle;

export class PlayerV8Adapter implements PlayerAPIv8 {

  private playerV7: PlayerAPIv7;
  private stateHandler: NativePlayerStateHandler;
  private playerExports: PlayerExports = {
    PlayerEvent: PlayerEventV8,
    ViewMode,
    WarningCode,
  } as any; // Only enums used by our UI are exported here

  private subtitlesApi: PlayerSubtitlesAPI = {
    list: () => {
      let subtitles = this.playerV7.getAvailableSubtitles();
      // As the 'off' subtitle gets added in v7 via an unshift() call,
      // we are removing it here again as it will be added through UI v3 anyway
      subtitles.shift();

      const currentSubtitle = this.playerV7.getSubtitle();
      return subtitles.map((subtitle: Subtitle) => {
        return {
          ...subtitle,
          enabled: subtitle.id === currentSubtitle.id,
          kind: 'subtitle',
        };
      });
    },
    enable: (id: string) => {
      this.playerV7.setSubtitle(id);
    },
    disable: (id: string) => {
      // As UI v3 sends 'null' as off id we have to set it explicitly
      this.playerV7.setSubtitle('off');
    },
    add(subtitle: SubtitleTrack): void {
    },
    remove(subtitleID: string): void {
    },
  };

  private bufferApi: PlayerBufferAPI = {
    getLevel: (type: BufferType, media: MediaType): BufferLevel => {
      return {
        level: this.getVideoBufferLength(),
        targetLevel: 0, // Not needed by our UI
        type,
        media,
      };
    },

    setTargetLevel(type: BufferType, value: number, media: MediaType): void {
      Logger.notImplemented('bufferApi.setTargetLevel');
    }
  };

  constructor(playerV7: PlayerAPIv7, stateHandler: NativePlayerStateHandler) {
    this.playerV7 = playerV7;
    this.stateHandler = stateHandler;
  }

  get exports(): PlayerExports {
    return this.playerExports;
  }

  get subtitles(): PlayerSubtitlesAPI {
    return this.subtitlesApi;
  }

  get buffer(): PlayerBufferAPI {
    return this.bufferApi;
  }

  on(eventType: PlayerEvent, callback: PlayerEventCallback): void {
    this.playerV7.addEventHandler(EventEnumMapper.mapToV7(eventType), callback);
  }

  off(eventType: PlayerEvent, callback: PlayerEventCallback): void {
    this.playerV7.removeEventHandler(EventEnumMapper.mapToV7(eventType), callback);
  }

  castStop(): void {
    this.playerV7.castStop();
  }

  castVideo(): void {
    this.playerV7.castVideo();
  }

  destroy(): Promise<void> {
    return Promise.resolve(this.playerV7.destroy());
  }

  getAudio(): AudioTrack {
    return {
      ...this.playerV7.getAudio(),
      getQualities: () => {
        Logger.notImplemented('getAvailableAudio.getQualities');
        return [];
      },
    };
  }

  getAudioBufferLength(): number {
    return this.playerV7.getAudioBufferLength();
  }

  getAudioQuality(): AudioQuality {
    return this.playerV7.getAudioQuality();
  }

  getAvailableAudio(): AudioTrack[] {
    const audioTracks = this.playerV7.getAvailableAudio();
    return audioTracks.map((track) => {
      return {
        ...track,
        getQualities: () => {
          Logger.notImplemented('getAvailableAudio.getQualities');
          return [];
        },
      };
    });
  }

  getAvailableAudioQualities(): AudioQuality[] {
    return this.playerV7.getAvailableAudioQualities();
  }

  getAvailableVideoQualities(): VideoQuality[] {
    return this.playerV7.getAvailableVideoQualities();
  }

  getConfig(mergedConfig?: boolean): PlayerConfig {
    return this.playerV7.getConfig();
  }

  getSource(): SourceConfig | null {
    if (!this.playerV7.isReady()) {
      return null;
    }

    return this.playerV7.getConfig().source;
  }

  getCurrentTime(): number {
    return this.playerV7.getCurrentTime();
  }

  getDownloadedAudioData(): DownloadedAudioData {
    return this.playerV7.getDownloadedAudioData();
  }

  getDownloadedVideoData(): DownloadedVideoData {
    return this.playerV7.getDownloadedVideoData();
  }

  getDuration(): number {
    return this.playerV7.getDuration();
  }

  getContainer(): HTMLElement {
    return this.playerV7.getFigure();
  }

  getMaxTimeShift(): number {
    return this.playerV7.getMaxTimeShift();
  }

  getPlaybackSpeed(): number {
    return this.playerV7.getPlaybackSpeed();
  }

  getStreamType(): StreamType {
    return this.playerV7.getStreamType() as StreamType;
  }

  getThumbnail(time: number): Thumbnail {
    const thumbnail = this.playerV7.getThumb(time);

    if (!thumbnail) {
      return null;
    }

    return {
      ...thumbnail,
      width: thumbnail.w,
      height: thumbnail.h,
    };
  }

  getTimeShift(): number {
    return this.playerV7.getTimeShift();
  }

  getVideoBufferLength(): number {
    return this.playerV7.getVideoBufferLength();
  }

  getVideoQuality(): VideoQuality {
    return this.playerV7.getVideoQuality();
  }

  getViewMode(): ViewMode {
    if (this.playerV7.isFullscreen()) {
      return ViewMode.Fullscreen;
    }

    // ViewMode.PictureInPicture is currently not supported

    return ViewMode.Inline;
  }

  getVolume(): number {
    return this.playerV7.getVolume();
  }

  hasEnded(): boolean {
    return this.playerV7.hasEnded();
  }

  isViewModeAvailable(viewMode: ViewMode): boolean {
    return viewMode !== ViewMode.PictureInPicture;
  }

  isAirplayAvailable(): boolean {
    return this.playerV7.isAirplayAvailable();
  }

  isAirplayActive(): boolean {
    return this.stateHandler.state.isAirplayActive;
  }

  showAirplayTargetPicker(): void {
    this.playerV7.showAirplayTargetPicker();
  }

  isCastAvailable(): boolean {
    return this.playerV7.isCastAvailable();
  }

  isCasting(): boolean {
    return this.playerV7.isCasting();
  }

  isLive(): boolean {
    return this.playerV7.isLive();
  }

  isMuted(): boolean {
    return this.playerV7.isMuted();
  }

  isPaused(): boolean {
    return this.playerV7.isPaused();
  }

  isPlaying(): boolean {
    return this.playerV7.isPlaying();
  }

  isStalled(): boolean {
    return this.playerV7.isStalled();
  }

  mute(): void {
    this.playerV7.mute();
  }

  pause(): void {
    this.playerV7.pause();
  }

  play(issuer?: string): Promise<void> {
    return new Promise<void>((resolve) => {
      this.playerV7.play();
      resolve();
    });
  }

  seek(time: number, issuer?: string): boolean {
    return this.playerV7.seek(time);
  }

  setAudio(trackID: string): void {
    this.playerV7.setAudio(trackID);
  }

  setAudioQuality(audioQualityID: string): void {
    this.playerV7.setAudioQuality(audioQualityID);
  }

  setPlaybackSpeed(speed: number): void {
    this.playerV7.setPlaybackSpeed(speed);
  }

  setVideoQuality(videoQualityID: string): void {
    this.playerV7.setVideoQuality(videoQualityID);
  }

  setViewMode(viewMode: ViewMode, options?: ViewModeOptions): void {
    if (viewMode === ViewMode.PictureInPicture) {
      return;
    }

    if (viewMode === ViewMode.Fullscreen) {
      this.playerV7.enterFullscreen();
    } else {
      this.playerV7.exitFullscreen();
    }
  }

  setVolume(volume: number): void {
    this.playerV7.setVolume(volume);
  }

  timeShift(offset: number): void {
    this.playerV7.timeShift(offset);
  }

  unmute(): void {
    this.playerV7.unmute();
  }

  // Not implemented

  readonly ads: PlayerAdvertisingAPI;
  readonly lowlatency: LowLatencyAPI;
  readonly version: string;
  readonly vr: PlayerVRAPI;

  addMetadata(metadataType: MetadataType.CAST, metadata: any): boolean {
    this.playerV7.addMetadata(metadataType, metadata);
    return false; // returning false as it's not implemented
  }

  clearQueryParameters(): void {
    this.playerV7.clearQueryParameters();
  }

  getAvailableSegments(): SegmentMap {
    Logger.notImplemented('getAvailableSegments');
    return undefined;
  }

  getBufferedRanges(): TimeRange[] {
    return this.playerV7.getBufferedRanges();
  }

  getDroppedVideoFrames(): number {
    return this.playerV7.getDroppedFrames();
  }

  getManifest(): string {
    Logger.notImplemented('getManifest');
    return undefined;
  }

  getPlaybackAudioData(): AudioQuality {
    return this.playerV7.getPlaybackAudioData();
  }

  getPlaybackVideoData(): VideoQuality {
    return this.playerV7.getPlaybackVideoData();
  }

  getPlayerType(): PlayerType {
    Logger.notImplemented('getPlayerType');
    return undefined;
  }

  getSeekableRange(): TimeRange {
    return this.playerV7.getSeekableRange();
  }

  getSnapshot(type?: string, quality?: number): Snapshot {
    return this.playerV7.getSnapshot(type, quality);
  }

  getSupportedDRM(): Promise<string[]> {
    return this.playerV7.getSupportedDRM();
  }

  getSupportedTech(mode?: SupportedTechnologyMode): Technology[] {
    Logger.notImplemented('getSupportedTech');
    return undefined;
  }

  getTotalStalledTime(): number {
    return this.playerV7.getTotalStalledTime();
  }

  getVideoElement(): HTMLVideoElement | HTMLObjectElement {
    Logger.notImplemented('getVideoElement');
    return undefined;
  }

  isDRMSupported(drmSystem: string): Promise<string> {
    return this.playerV7.isDRMSupported(drmSystem);
  }

  load(source: SourceConfig, forceTechnology?: string, disableSeeking?: boolean): Promise<void> {
    Logger.notImplemented('load');
    return undefined;
  }

  preload(): void {
    this.playerV7.preload();
  }

  setAuthentication(customData: any): void {
    this.playerV7.setAuthentication(customData);
  }

  setLogLevel(level: LogLevel): void {
    Logger.notImplemented('setLogLevel');
  }

  setPosterImage(url: string, keepPersistent: boolean): void {
    this.playerV7.setPosterImage(url, keepPersistent);
  }

  setQueryParameters(queryParameters: QueryParameters): void {
    this.playerV7.setQueryParameters(queryParameters);
  }

  setVideoElement(videoElement: HTMLElement): void {
    this.playerV7.setVideoElement(videoElement);
  }

  unload(): Promise<void> {
    this.playerV7.unload();
    return undefined;
  }
}
