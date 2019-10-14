import { NativeCommunicator } from './NativeCommunicator';

interface ConsoleLogFunction {
  (message?: any, ...optionalParams: any[]): void;
}

enum LogLevel {
  log = 'Debug',
  warn = 'Warning',
  error = 'Error',
}

export class Logger {
  static notImplemented(methodName: string) {
    const message = `'${methodName}' not implemented in NativePlayerAdapter`;
    this.warn(message);
  }

  static log(message: string, ...attributes: any[]) {
    this.logWeb(console.log, message, ...attributes);
    this.logNative(LogLevel.log, message, ...attributes);
  }

  static warn(message: string, ...attributes: any[]) {
    this.logWeb(console.warn, message, ...attributes);
    this.logNative(LogLevel.warn, message, ...attributes);
  }

  static error(message: string, ...attributes: any[]) {
    this.logWeb(console.error, message, ...attributes);
    this.logNative(LogLevel.error, message, ...attributes);
  }

  private static logWeb(consoleFunction: ConsoleLogFunction, message: string, ...attributes: any[]) {
    consoleFunction(message, attributes);
  }

  private static logNative(errorLevel: LogLevel, message: string, ...attributes: any[]) {
    const payload = {
      errorLevel,
      message,
      attributes,
    };

    NativeCommunicator.postEvent('logMessage', payload);
  }
}
