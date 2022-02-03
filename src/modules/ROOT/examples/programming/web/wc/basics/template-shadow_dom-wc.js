class TemplateHelloWorld extends HTMLElement {
    constructor() {
        super();

        // get the reference to the template
        let templateReference = document.querySelector('#my-template-shadow-dom-wc');
        
        // get the content node
        let templateContent = templateReference.content;

        let shadowRoot = this.attachShadow({ mode: 'open' });

        // add a text node
        shadowRoot.append(templateContent.cloneNode(true));
    }
}

customElements.define('template-wc', TemplateHelloWorld);