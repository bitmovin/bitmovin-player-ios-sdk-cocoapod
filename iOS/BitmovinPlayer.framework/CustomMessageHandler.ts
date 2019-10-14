declare const window: any;

interface MessageHandler {
  (data?: string): void;
}

export class CustomMessageHandler {
  private static PROMPT_IDENTIFIER = 'BMPCustomMessageHandler';
  private messageCallbacks: { [messageIdentifier: string]: MessageHandler[]; } = {};

  /**
   * Sends a message with optional data synchronous to the CustomMessageHandler on the native environment
   *
   * @param name The name of the message
   * @param data The data of the message (Can be a stringifyed object)
   * @returns string | null
   */
  sendSynchronous(name: string, data?: string): string | null {
    // Create a custom payload object to distinguish if the prompt call was triggered by the CustomMessageHandler,
    // by our internal default communication or by something else.
    const payload = { name, data };
    return prompt(CustomMessageHandler.PROMPT_IDENTIFIER, JSON.stringify(payload));
  }

  /**
   * Sends a message with optional data asynchronous to the CustomMessageHandler on the native environment
   *
   * @param name The name of the message
   * @param data The data of the message (Can be a stringifyed object)
   */
  sendAsynchronous(name: string, data?: string): void {
    const payload = { name, data };
    // The name for the message handler is defined in BMPBitmovinPlayerUIController.m and must match
    if (!window.webkit.messageHandlers.customMessageHandler) {
      console.warn('No customMessageHandler defined in the styleConfiguration.userInterfaceConfiguration');
      return;
    }

    window.webkit.messageHandlers.customMessageHandler.postMessage(payload);
  }

  /**
   * Register a callback to a given methodName which then can be called from the native CustomMessageHandler
   *
   * @param methodName
   * @param callback
   */
  on(methodName: string, callback: MessageHandler): void {
    if (!this.messageCallbacks[methodName]) {
      this.messageCallbacks[methodName] = [];
    }

    this.messageCallbacks[methodName].push(callback);
  }

  /**
   * This will be called from the native part when triggering a message
   *
   * @hidden
   *
   * TODO: find a proper way to hide this
   */
  triggerMessage(methodName: string, data?: string): void {
    if (this.messageCallbacks[methodName]) {
      this.messageCallbacks[methodName].forEach((callback: MessageHandler) => callback(data));
    }
  }
}
