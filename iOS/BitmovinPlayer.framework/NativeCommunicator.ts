import { BitmovinWindow } from '../BitmovinWindow';

declare const window: BitmovinWindow;

// send messages to the iOS native environment
export namespace NativeCommunicator {
  export function postEvent(event: string, parameters: object = {}): void {
    const message = Object.assign({ event: event }, parameters);
    window.webkit.messageHandlers.ios.postMessage(message);
  }

  export function callSynchronously(functionName: string, data: any): string {
    const type = "BMPJSBridge";
    const payload = {
      functionName: functionName,
      data: data
    };

    return prompt(type, JSON.stringify(payload));
  }
}
