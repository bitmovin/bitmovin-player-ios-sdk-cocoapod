export class JsLoader {
  static load(file: string): Promise<void> {
    // retrieve the js element
    let jsElement = document.getElementById('uijs') as HTMLScriptElement;

    if (jsElement && file === jsElement.src) {
      // file already loaded
      return Promise.resolve();
    }

    if (jsElement) {
      this.removeElement(jsElement);
    }

    jsElement = this.createScriptElement('uijs');
    this.addElementToHead(jsElement);

    return new Promise<void>((resolve) => {
      jsElement.addEventListener('load', () => resolve());
      jsElement.src = file;
    });
  }

  private static createScriptElement(id: string): HTMLScriptElement {
    const jsElement = document.createElement('script');
    jsElement.type = 'text/javascript';
    jsElement.setAttribute('id', id);
    return jsElement;
  }

  private static addElementToHead(element: HTMLElement) {
    document.getElementsByTagName('head').item(0).appendChild(element);
  }

  private static removeElement(element: HTMLElement) {
    element.parentElement.removeChild(element);
  }
}
