export default class CustomButton extends HTMLElement {
    constructor() {
        super();

        this.timesClicked = 0;

        let template = `
            <button>click me</button>
            <span>${this.getTimesClicked()}</span>`;
        this.innerHTML = template;
    }

    connectedCallback(){
        /* this.querySelector('button')
            .addEventListener('click', (e) => {
                this.handleClick(e);
            }) */
        this.querySelector('button')
            .addEventListener('click', this.handleClick.bind(this));
    }

    disconnectedCallback(){
        console.log('we are inside disconnectedCallback');
        this.querySelector('button')
            .removeEventListener('click', this.handleClick);
    }

    handleClick(){
        this.timesClicked++;
        this.querySelector('span').innerText = this.getTimesClicked();
    }

    getTimesClicked() {
        return `Times clicked: ${this.timesClicked}`;
    }
}