export class FullscreenSupportHandler {
  static changeButtonVisibility(visible: boolean) {
    // FIXME: not really sophisticated to use this class here
    //        a customer could use another prefix (bmpui) or even rename it completely
    //        Possible Solution: use isViewModeAvailable in v8 player (not possible in v7, and also not used by UI)
    const fullscreenToggleButtons = document.getElementsByClassName("bmpui-ui-fullscreentogglebutton");
    const display = visible ? 'block' : 'none';

    Array.from(fullscreenToggleButtons).forEach((button: HTMLElement) => {
      button.style.display = display;
    });
  }
}
