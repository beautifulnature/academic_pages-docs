export default class TimeSlot extends HTMLElement {
    constructor(){
        super();
        this.render();
    }

    render(){
        let templateRef = document.querySelector('#time-slot-template');
        let templateContent = templateRef.content;
        let shadowRoot = this.attachShadow({mode: 'open'});
        shadowRoot.append(templateContent.cloneNode(true));
    }
}