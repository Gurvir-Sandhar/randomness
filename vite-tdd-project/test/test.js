//stack implementation without using array

class Stack {
    constructor() {
      this.top = -1;
      this.items = {};
    }
    
    pushTop(item) {
      this.top += 1;
      this.items[this.top] = item;
    }

    removeTop() {
      let temp = this.top;
      this.top -= 1;
      return this.items[temp];
    }
}


describe("my stack", () => {

  let stack;
  beforeEach(()=> {
    stack = new Stack();
  })

    it('is created empty', () => {
        expect(stack.top).toBe(-1);
        expect(stack.items).toEqual({});
    })

    it('can push item to the top', () =>  {
      stack.pushTop(5);
      expect(stack.top).toBe(0);
      expect(stack.items[0]).toBe(5);
    })

    it('can pop item from the top', () => {
      stack.pushTop(5);
      stack.pushTop(9);
      let temp = stack.removeTop(); expect(temp).toBe(9); expect(stack.top).toBe(0); expect(stack.items[0]).toBe(5); })
})