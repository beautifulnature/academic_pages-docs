class HelloShadow extends HTMLElement {
    constructor() {
        super();

        let shadowRoot = this.attachShadow({ mode: 'open' });
        shadowRoot.append('Hello shadow DOM from web component');
    }
}

customElements.define('hello-shadow', HelloShadow);