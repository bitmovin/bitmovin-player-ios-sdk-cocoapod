export class CssLoader {

  /**
   * Adds the given CSS file to the site. There must be already a `<link>` HTML element present in the HTML site which has
   * its `id` set to the value given by the parameter identifier. This function sets the `href` attribute on this <link>
   * tag and calls the finishedCallback as soon as the CSS file was loaded correctly.
   *
   * @param file the CSS file which should be added to the site
   * @param identifier The id to identify the `<link>` tag in the HTML site on which the CSS file should be set
   */
  static load(file: string, identifier: string): Promise<void> {
    // Retrieve the `<link>` element from the DOM
    const cssElement = document.getElementById(identifier) as HTMLStyleElement;

    if (!cssElement) {
      return Promise.resolve();
    }

    const currentCSS = cssElement.getAttribute('href');
    if (file === currentCSS) {
      return Promise.resolve();
    }

    return new Promise<void>((resolve) => {
      cssElement.addEventListener('load', () => resolve());
      cssElement.setAttribute('href', file);
    });
  }
}
