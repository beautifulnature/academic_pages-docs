export default class HeaderImage extends HTMLElement {
    constructor() {
        super();
        this.innerHTML = this.getTemplate();
    }

    getTemplate() {
        return `
            <div>
                <img src="${this.getAttribute('src')}"
                    alt="${this.getAttribute('alt')}" />
                ${this.handleErrors()}
            </div>
            <style>
                img {
                    width: 400px;
                }
            </style>
            `;
    }

    handleErrors() {
        if (!this.getAttribute('alt')) {
            return `
                <div class="error">Missing Alt text</div>
                <style>
                    .error {
                        color: red;
                    }
                </style>    
            `;
        }
        return ``;
    }
}