export default class CustomClicker extends HTMLElement {
    constructor() {
        super();
        this._num = 0;
        this.shadowObj = this.attachShadow({ mode: 'open' });
        this.render();
    }

    connectedCallback() {
        this.shadowObj.querySelector('.js-button')
            .addEventListener("click", (e) => {
                this.handleClick(e);
            });
    }

    render() {
        this.shadowObj.innerHTML = this.getTemplate();
    }

    handleClick() {
        this._num++;
        this.shadowObj.querySelector('.custom-clicker__num').innerHTML = this.getTimesClicked();
        this.dispatchEvent(new CustomEvent('change', {
            detail: {
                num: this._num,
            },
            bubbles: true,
        }));
    }

    getTemplate() {
        return `
            <div class="custom-clicker__contatiner">
                <div class="custom-clicker__num">${this.getTimesClicked()}</div>
                <button class="js-button custom-clicker__button">Click Me</button>
            </div>
            ${this.getStyle()}
        `;
    }

    getTimesClicked() {
        return `${this._num} times clicked.`;
    }

    getStyle() {
        return `
          <style>
            :host {
              display: block;
            }
            .custom-clicker__button {
              height: 50px;
              width: 200px;
              border-radius: 5px;
              display: inline-block;
              border: 1px solid #cac6c6;
            }
          </style>
        `;
    }
}