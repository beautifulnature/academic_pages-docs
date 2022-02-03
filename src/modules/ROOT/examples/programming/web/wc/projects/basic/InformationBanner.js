export default class InformationBanner extends HTMLElement {
    constructor() {
        super();
        this.render();
    }

    render(){
        let templateRef = document.querySelector('#information-banner-tempalte');
        let templateContent = templateRef.content;
        let shadowRoot = this.attachShadow({mode: 'open'});
        shadowRoot.append(templateContent.cloneNode(true));
    }
}