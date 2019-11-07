import SupportedTech = bitmovin.PlayerAPI.SupportedTech;
import Config = bitmovin.PlayerAPI.Config;
import ScheduleAdOptions = bitmovin.PlayerAPI.ScheduleAdOptions;
import EVENT = bitmovin.PlayerAPI.EVENT;
import Subtitle = bitmovin.PlayerAPI.Subtitle;
import PlayerStatic = bitmovin.PlayerStatic;
import EventList = bitmovin.PlayerAPI.EventList;
import PlayerAPI = bitmovin.PlayerAPI;
import PlayerEventCallback = bitmovin.PlayerAPI.PlayerEventCallback;
import VideoQuality = bitmovin.PlayerAPI.VideoQuality;
import DownloadedAudioData = bitmovin.PlayerAPI.DownloadedAudioData;
import DownloadedVideoData = bitmovin.PlayerAPI.DownloadedVideoData;
import SourceConfig = bitmovin.PlayerAPI.SourceConfig;
import AudioQuality = bitmovin.PlayerAPI.AudioQuality;
import AudioTrack = bitmovin.PlayerAPI.AudioTrack;
import PlayerVRAPI = bitmovin.PlayerAPI.PlayerVRAPI;
import TimeRange = bitmovin.PlayerAPI.TimeRange;
import Snapshot = bitmovin.PlayerAPI.Snapshot;
import Thumbnail = bitmovin.PlayerAPI.Thumbnail;
import Status = bitmovin.PlayerAPI.VR.Status;
import { NativeCommunicator } from './helper/NativeCommunicator';
import { NativePlayerStateHandler } from './NativePlayerStateHandler';
import { EventEmitter } from './EventEmitter';
import { Logger } from './helper/Logger';
import { PlayerEventV7 } from './v7/PlayerEnums';
import { BufferType } from './v8/PlayerV8Enums';

export class NativePlayerAdapter implements PlayerAPI {

  private nativeStateHandler: NativePlayerStateHandler;
  private eventEmitter: EventEmitter;

  constructor(nativeStateHandler: NativePlayerStateHandler, eventEmitter: EventEmitter) {
    this.nativeStateHandler = nativeStateHandler;
    this.eventEmitter = eventEmitter;
  }

  get EVENT(): EventList {
    return PlayerEventV7;
  }

  addEventHandler(eventType: EVENT, callback: PlayerEventCallback): PlayerAPI {
    this.eventEmitter.on(eventType, callback);
    return this;
  }

  removeEventHandler(eventType: EVENT, callback: PlayerEventCallback): PlayerAPI {
    this.eventEmitter.off(eventType, callback);
    return this;
  }

  castStop(): PlayerAPI {
    NativeCommunicator.postEvent('castStop');
    return this;
  }

  castVideo(): PlayerAPI {
    NativeCommunicator.postEvent('castVideo');
    return this;
  }

  enterFullscreen(): void {
    NativeCommunicator.postEvent('enterFullscreen');
  }

  exitFullscreen(): void {
    NativeCommunicator.postEvent('exitFullscreen');
  }

  getAudio(): AudioTrack {
    return this.nativeStateHandler.state.audio;
  }

  getAvailableAudio(): AudioTrack[] {
    return this.nativeStateHandler.state.availableAudio;
  }

  getAvailableAudioQualities(): AudioQuality[] {
    return [];
  }

  getAvailableSubtitles(): Subtitle[] {
    return this.getAvailableSubtitlesArray();
  }

  private getAvailableSubtitlesArray(): Subtitle[] {
    const subtitles: Subtitle[] = Object.keys(this.nativeStateHandler.state.availableSubtitlesById).map((key) => {
      return this.nativeStateHandler.state.availableSubtitlesById[key];
    });

    if (subtitles.length > 0) {
      subtitles.unshift({
        id: 'off',
        url: null,
        lang: null,
        label: 'off',
      });
    }

    return subtitles;
  }

  getAvailableVideoQualities(): VideoQuality[] {
    return [];
  }

  getConfig(mergedConfig?: boolean): any {
    return this.nativeStateHandler.state.config;
  }

  getCurrentTime(): number {
    return this.nativeStateHandler.state.currentTime;
  }

  getDuration(): number {
    return this.nativeStateHandler.state.duration;
  }

  getFigure(): HTMLElement {
    return document.getElementById('ui-container');
  }

  getMaxTimeShift(): number {
    return this.nativeStateHandler.state.maxTimeShift;
  }

  getPlaybackSpeed(): number {
    return this.nativeStateHandler.state.playbackSpeed;
  }

  getSubtitle(): Subtitle {
    return this.nativeStateHandler.state.subtitle;
  }

  getThumb(time: number): Thumbnail {
    const thumbnailString = NativeCommunicator.callSynchronously('thumbnailForTime:', time);
    if (thumbnailString) {
      return JSON.parse(thumbnailString);
    }
    return null;
  }

  getTimeShift(): number {
    return this.nativeStateHandler.state.timeShift;
  }

  getVolume(): number {
    return this.nativeStateHandler.state.volume;
  }

  isAirplayAvailable(): boolean {
    return this.nativeStateHandler.state.isAirplayAvailable;
  }

  showAirplayTargetPicker(): PlayerAPI {
    NativeCommunicator.postEvent('showAirplayTargetPicker');
    return this;
  }

  isCastAvailable(): boolean {
    return this.nativeStateHandler.state.isCastAvailable;
  }

  isCasting(): boolean {
    return this.nativeStateHandler.state.isCasting;
  }

  isFullscreen(): boolean {
    return this.nativeStateHandler.state.isFullscreen;
  }

  isLive(): boolean {
    return this.nativeStateHandler.state.isLive;
  }

  isMuted(): boolean {
    return this.nativeStateHandler.state.isMuted;
  }

  isPaused(): boolean {
    return this.nativeStateHandler.state.isPaused;
  }

  isPlaying(): boolean {
    return this.nativeStateHandler.state.isPlaying;
  }

  isReady(): boolean {
    return this.nativeStateHandler.state.isReady;
  }

  isSetup(): boolean {
    return true;
  }

  mute(issuer?: string): PlayerAPI {
    NativeCommunicator.postEvent('mute');
    return this;
  }

  pause(issuer?: string): PlayerAPI {
    NativeCommunicator.postEvent('pause');
    return this;
  }

  play(issuer?: string): PlayerAPI {
    NativeCommunicator.postEvent('play');
    return this;
  }

  seek(time: number, issuer?: string): boolean {
    this.nativeStateHandler.state.currentTime = time;
    NativeCommunicator.postEvent('seek', { 'time': time });
    return true;
  }

  setAudio(trackID: string): PlayerAPI {
    if (this.nativeStateHandler.state.audio && trackID === this.nativeStateHandler.state.audio.id) {
      return;
    }

    NativeCommunicator.postEvent('setAudio', { 'trackID': trackID });
    return this;
  }

  setPlaybackSpeed(speed: number): void {
    if (!isFinite(speed)) {
      return;
    }
    speed = Number(speed);
    if (speed <= 0) {
      return;
    }
    this.nativeStateHandler.state.playbackSpeed = speed;
    NativeCommunicator.postEvent('setPlaybackSpeed', { 'speed': speed });
  }

  setSubtitle(trackID: string): PlayerAPI {
    if (this.nativeStateHandler.state.subtitle && trackID === this.nativeStateHandler.state.subtitle.id) {
      return;
    }
    NativeCommunicator.postEvent('setSubtitle', { 'trackID': trackID });
  }

  setVolume(volume: number, issuer?: string): PlayerAPI {
    if (!isFinite(volume)) {
      return;
    }
    volume = Number(volume);
    if (volume < 0) {
      return;
    }
    this.nativeStateHandler.state.volume = volume;
    NativeCommunicator.postEvent('setVolume', { 'volume': volume });

    return this;
  }

  timeShift(offset: number, issuer?: string): PlayerAPI {
    this.nativeStateHandler.state.timeShift = offset;
    NativeCommunicator.postEvent('timeShift', { 'offset': offset });

    return this;
  }

  unmute(issuer?: string): PlayerAPI {
    NativeCommunicator.postEvent('unmute');
    return this;
  }

  on(eventType: string, callback: PlayerEventCallback): PlayerAPI {
    return this.addEventHandler(eventType, callback);
  }

  off(eventType: string, callback: PlayerEventCallback): PlayerAPI {
    return this.removeEventHandler(eventType, callback);
  }

  isPictureInPictureAvailable(): boolean {
    return false;
  }

  isPictureInPicture(): boolean {
    return false;
  }

  getVideoBufferLength(): number | null {
    const bufferSizeString = NativeCommunicator.callSynchronously('buffer.getLevel', BufferType.ForwardDuration);
    const bufferSize = parseFloat(bufferSizeString);

    return isNaN(bufferSize) ? 0 : bufferSize;
  }

  getAudioBufferLength(): number | null {
    // The native player can't distinguish between audio and video so returning the same in both methods is sufficient
    return this.getVideoBufferLength();
  }

  // This methods are not implemented within the native <> JS bridge

  VR: PlayerStatic['VR'];
  version: string;
  vr: PlayerVRAPI;

  addMetadata(metadataType: string, metadata: any): void {
    Logger.notImplemented('addMetadata');
  }

  addSubtitle(subtitle: Subtitle): PlayerAPI {
    Logger.notImplemented('addSubtitle');
    return undefined;
  }

  clearQueryParameters(): PlayerAPI {
    Logger.notImplemented('clearQueryParameters');
    return undefined;
  }

  destroy(): void {
    Logger.notImplemented('destroy');
  }

  enterPictureInPicture(): PlayerAPI {
    Logger.notImplemented('enterPictureInPicture');
    return undefined;
  }

  exitPictureInPicture(): PlayerAPI {
    Logger.notImplemented('exitPictureInPicture');
    return undefined;
  }

  fireEvent(event: string, data: {}): void {
    Logger.notImplemented('fireEvent');
  }

  getAudioQuality(): AudioQuality {
    Logger.notImplemented('getAudioQuality');
    // This is needed to prevent a crash in the UI where it want's to access the audio quality even no audio qualities
    // exists.
    return {} as AudioQuality;
  }

  getAvailableImpressionServers(): string[] {
    Logger.notImplemented('getAvailableImpressionServers');
    return [];
  }

  getAvailableLicenseServers(): string[] {
    Logger.notImplemented('getAvailableLicenseServers');
    return [];
  }

  getBufferedRanges(): TimeRange[] {
    Logger.notImplemented('getBufferedRanges');
    return [];
  }

  getDroppedFrames(): number {
    Logger.notImplemented('getDroppedFrames');
    return 0;
  }

  getManifest(): Object {
    Logger.notImplemented('getManifest');
    return undefined;
  }

  getPlaybackAudioData(): AudioQuality {
    Logger.notImplemented('getPlaybackAudioData');
    return undefined;
  }

  getPlaybackVideoData(): VideoQuality {
    Logger.notImplemented('getPlaybackVideoData');
    return undefined;
  }

  getPlayerType(): string {
    Logger.notImplemented('getPlayerType');
    return "";
  }

  getSeekableRange(): TimeRange {
    Logger.notImplemented('getSeekableRange');
    return undefined;
  }

  getSnapshot(type?: string, quality?: number): Snapshot {
    Logger.notImplemented('getSnapshot');
    return undefined;
  }

  getStreamType(): string {
    Logger.notImplemented('getStreamType');
    return "";
  }

  getSupportedDRM(): Promise<string[]> {
    Logger.notImplemented('getSupportedDRM');
    return undefined;
  }

  getSupportedTech(): SupportedTech[] {
    Logger.notImplemented('getSupportedTech');
    return [];
  }

  getTotalStalledTime(): number {
    Logger.notImplemented('getTotalStalledTime');
    return 0;
  }

  getVRStatus(): Status {
    Logger.notImplemented('getVRStatus');
    return undefined;
  }

  getVideoQuality(): VideoQuality {
    Logger.notImplemented('getVideoQuality');
    // This is needed to prevent a crash in the UI where it want's to access the video quality even no video qualities
    // exists.
    return {} as VideoQuality;
  }

  getDownloadedAudioData(): DownloadedAudioData {
    Logger.notImplemented('getDownloadedAudioData');
    return undefined;
  }

  getDownloadedVideoData(): DownloadedVideoData {
    Logger.notImplemented('getDownloadedVideoData');
    return undefined;
  }

  hasEnded(): boolean {
    Logger.notImplemented('hasEnded');
    return false;
  }

  isAd(): boolean {
    Logger.notImplemented('isAd');
    return false;
  }

  isDRMSupported(drmSystem: string): Promise<string> {
    Logger.notImplemented('isDRMSupported');
    return undefined;
  }

  isStalled(): boolean {
    Logger.notImplemented('isStalled');
    return false;
  }

  load(source: SourceConfig, forceTechnology?: string, disableSeeking?: boolean): Promise<PlayerAPI> {
    Logger.notImplemented('load');
    return undefined;
  }

  preload(): PlayerAPI {
    Logger.notImplemented('preload');
    return undefined;
  }

  removeSubtitle(subtitleTrackID: string): PlayerAPI {
    Logger.notImplemented('removeSubtitle');
    return undefined;
  }

  scheduleAd(adManifestUrl: string, adType: string, options?: ScheduleAdOptions): void {
    Logger.notImplemented('scheduleAd');
  }

  setAudioQuality(audioQualityID: string): PlayerAPI {
    Logger.notImplemented('setAudioQuality');
    return undefined;
  }

  setAuthentication(customData: any): void {
    Logger.notImplemented('setAuthentication');
  }

  setLastSegment(lastSegmentNum: number): PlayerAPI {
    Logger.notImplemented('setLastSegment');
    return undefined;
  }

  setPosterImage(url: string, keepPersistent: boolean): void {
    Logger.notImplemented('setPosterImage');
  }

  setQueryParameters(queryParameters: { [p: string]: string }): PlayerAPI {
    Logger.notImplemented('setQueryParameters');
    return undefined;
  }

  setVRStereo(enableStereo: boolean): boolean {
    Logger.notImplemented('setVRStereo');
    return false;
  }

  setVideoElement(videoElement: HTMLElement): void {
    Logger.notImplemented('setVideoElement');
  }

  setVideoQuality(videoQualityID: string): PlayerAPI {
    Logger.notImplemented('setVideoQuality');
    return undefined;
  }

  setup(userConfig: Config, forceTechnology?: string): Promise<PlayerAPI> {
    Logger.notImplemented('setup');
    return undefined;
  }

  skipAd(): void {
    Logger.notImplemented('skipAd');
  }

  unload(): PlayerAPI {
    Logger.notImplemented('unload');
    return undefined;
  }
}
