export default class OnlineChecker extends HTMLElement {
    constructor() {
        super();
        this._isOnline = false;
        this.shadowObj = this.attachShadow({ mode: 'open' });
    }

    connectedCallback() {
        this.isOnline = navigator.onLine;
        this.render();
    }

    render() {
        this.shadowObj.innerHTML = this.getTemplate();
    }

    getTemplate() {
        return `
            <span class="online-status online-${this._isOnline ? 'true' : 'false'}"></span>
            <span>${this._isOnline ? 'Online' : 'offline'}</span>
            ${this.getStyle()}
        `;
    }

    getStyle() {
        return `
            <style>
                :host {
                    display: inline-block;
                    border: 1px solid #cac6c6;
                    padding: 10px;
                    border-radius: 5px;
                }
                .online-status {
                    height: 10px;
                    width: 10px;
                    border-radius: 50%;
                    display: inline-block;
                }
                .online-true {
                    background-color: green;
                }
                .online-false {
                    background-color: red;
                }
            </style>
        `;
    }

    get isOnline() {
        return this._isOnline;
    }

    set isOnline(value) {
        if (value !== this._isOnline) {
            this._isOnline = value;
            this.render();
        }
    }
}