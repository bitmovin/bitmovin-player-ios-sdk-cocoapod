import Subtitle = bitmovin.PlayerAPI.Subtitle;
import AudioTrack = bitmovin.PlayerAPI.AudioTrack;

interface NativePlayerConfig {
  source: object;
}

export interface NativePlayerState {
  duration: number,
  currentTime: number,
  maxTimeShift: number,
  timeShift: number,
  isPlaying: boolean,
  isPaused: boolean,
  isLive: boolean,
  isCastAvailable: boolean,
  isCasting: boolean,
  isReady: boolean,
  isMuted: boolean,
  config: NativePlayerConfig,
  availableAudio: AudioTrack[],
  audio?: AudioTrack,
  availableSubtitlesById: { [key: string]: Subtitle },
  subtitle?: Subtitle,
  playbackSpeed: number,
  isFullscreen: boolean,
  volume: number,
  isAirplayAvailable: boolean,
  isAirplayActive: boolean,
}

export class NativePlayerStateHandler {

  private nativePlayerState: NativePlayerState = {
    duration: 0,
    currentTime: 0,
    maxTimeShift: 0,
    timeShift: 0,
    isPlaying: false,
    isPaused: false,
    isLive: false,
    isCastAvailable: false,
    isCasting: false,
    isReady: false,
    isMuted: false,
    config: {
      source: {},
    },
    availableSubtitlesById: {},
    availableAudio: [],
    audio: null,
    subtitle: null,
    playbackSpeed: 1,
    isFullscreen: false,
    volume: 100,
    isAirplayAvailable: false,
    isAirplayActive: false,
  };

  constructor() {
    this.initAppState();
  }

  get state(): NativePlayerState {
    return this.nativePlayerState;
  }

  reset(): void {
    this.initAppState();
  }

  private initAppState(): void {
    this.nativePlayerState.duration = 0;
    this.nativePlayerState.currentTime = 0;
    this.nativePlayerState.maxTimeShift = 0;
    this.nativePlayerState.timeShift = 0;
    this.nativePlayerState.isPlaying = false;
    this.nativePlayerState.isPaused = false;
    this.nativePlayerState.isReady = false;
    this.nativePlayerState.availableSubtitlesById = {};
    this.nativePlayerState.availableAudio = [];
    this.nativePlayerState.audio = null;
    this.nativePlayerState.subtitle = null;
  }
}
