1. Interface

        Conceito: Em C, não há suporte nativo para interfaces como em linguagens 
        orientadas a objetos. No entanto, você pode simular interfaces usando 
        ponteiros para funções em structs. A ideia é definir uma estrutura que 
        contenha os ponteiros para as funções que devem ser implementadas.

        Exemplo:
        Vamos criar uma "interface" para uma forma geométrica (Shape) que tem 
        um método draw.

        c

        #include <stdio.h>

        typedef struct {
        void (*draw)(void*);  // Ponteiro para função draw
        } Shape;

        typedef struct {
        Shape shape;
        int radius;
        } Circle;

        void draw_circle(void* c) {
        Circle* circle = (Circle*)c;
        printf("Drawing a circle with radius %d\n", circle->radius);
        }

        Circle* create_circle(int radius) {
        Circle* circle = (Circle*)malloc(sizeof(Circle));
        circle->shape.draw = draw_circle;  // Implementação do método draw
        circle->radius = radius;
        return circle;
        }

        int main() {
        Circle* circle = create_circle(5);
        circle->shape.draw(circle);  // Chama a função draw da "interface"
        free(circle);
        return 0;
        }

        Explicação:

        Shape: Define um ponteiro para a função draw, que será implementada 
        pelas estruturas que representam formas específicas (neste caso, um 
        círculo).

        Circle: Implementa a função draw específica para desenhar um círculo.
        Polimorfismo: Você pode chamar draw para qualquer estrutura que siga 
        essa interface, sem precisar conhecer sua implementação exata.

2. Encapsulamento

        Conceito: Encapsulamento envolve esconder os detalhes de implementação
        de uma estrutura de dados ou função, expondo apenas uma interface pú-
        blica para interagir com ela.

        Exemplo:
        Vamos encapsular os detalhes internos de uma estrutura MyClass, expon-
        do apenas funções para acessar e modificar seus dados.

        c

        #include <stdio.h>
        #include <stdlib.h>

        typedef struct {
        int private_data;  // Dados privados
        } MyClass;

        // Função para criar uma nova instância de MyClass
        MyClass* create_myclass(int initial_value) {
        MyClass* obj = (MyClass*)malloc(sizeof(MyClass));
        obj->private_data = initial_value;
        return obj;
        }

        // Função para definir o valor de private_data
        void set_data(MyClass* obj, int data) {
        obj->private_data = data;
        }

        // Função para obter o valor de private_data
        int get_data(MyClass* obj) {
        return obj->private_data;
        }

        int main() {
        MyClass* my_obj = create_myclass(10);
        printf("Initial value: %d\n", get_data(my_obj));

        set_data(my_obj, 20);
        printf("Updated value: %d\n", get_data(my_obj));

        free(my_obj);
        return 0;
        }

        Explicação:

        Encapsulamento: A estrutura MyClass tem um membro private_data que é 
        acessado e modificado apenas através de funções específicas 
        (set_data e get_data).
        
        Controle: Isso permite controlar como os dados internos são manipula-
        dos, prevenindo acessos diretos que poderiam levar a erros.

3. Abstração

        Conceito: Abstração é o processo de ocultar os detalhes complexos de 
        uma operação, expondo apenas uma interface simples e intuitiva.

        Exemplo:
        Vamos criar uma abstração para a manipulação de uma lista ligada 
        (linked list).

        c

        #include <stdio.h>
        #include <stdlib.h>

        typedef struct Node {
        int data;
        struct Node* next;
        } Node;

        typedef struct {
        Node* head;
        } LinkedList;

        LinkedList* create_list() {
        LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
        list->head = NULL;
        return list;
        }

        void add_node(LinkedList* list, int data) {
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = data;
        new_node->next = list->head;
        list->head = new_node;
        }

        void print_list(LinkedList* list) {
        Node* current = list->head;
        while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
        }
        printf("NULL\n");
        }

        int main() {
        LinkedList* list = create_list();
        add_node(list, 1);
        add_node(list, 2);
        add_node(list, 3);

        print_list(list);

        // Liberar a memória da lista (não implementado aqui para simplificar)
        return 0;
        }

        Explicação:

        Abstração: A estrutura LinkedList e suas funções (add_node, print_list)
         abstraem os detalhes de como a lista ligada é implementada, permitin-
         do que o usuário da lista interaja com ela de forma simples e intui-
         tiva.
        Ocultação de Complexidade: O usuário da lista não precisa saber como 
        os nós são alocados ou ligados, apenas como adicionar elementos e im-
        primir a lista.

4. Hereditariedade e Polimorfismo

        Conceito: Em C, a herança e o polimorfismo podem ser simulados usando 
        ponteiros para funções e estruturas. Isso permite que diferentes 
        "subclasses" compartilhem uma interface comum.

        Exemplo:
        Vamos criar uma simulação simples de herança e polimorfismo usando 
        uma "classe base" Animal e duas "subclasses" Dog e Cat.

        c

        #include <stdio.h>
        #include <stdlib.h>

        typedef struct {
                void (*speak)(void*);
        } Animal;

        typedef struct {
                Animal animal;
                char* name;
        } Dog;

        typedef struct {
                Animal animal;
                char* name;
        } Cat;

        void dog_speak(void* d) {
                Dog* dog = (Dog*)d;
                printf("%s says: Woof!\n", dog->name);
        }

        void cat_speak(void* c) {
                Cat* cat = (Cat*)c;
                printf("%s says: Meow!\n", cat->name);
        }

        Dog* create_dog(char* name) {
                Dog* dog = (Dog*)malloc(sizeof(Dog));
                dog->animal.speak = dog_speak;
                dog->name = name;
                return dog;
        }

        Cat* create_cat(char* name) {
                Cat* cat = (Cat*)malloc(sizeof(Cat));
                cat->animal.speak = cat_speak;
                cat->name = name;
                return cat;
        }

        void animal_speak(Animal* animal, void* context) {
                animal->speak(context);
        }

        int main() {
                Dog* dog = create_dog("Buddy");
                Cat* cat = create_cat("Whiskers");

                animal_speak((Animal*)dog, dog);  // Chama o método speak do Dog
                animal_speak((Animal*)cat, cat);  // Chama o método speak do Cat

                free(dog);
                free(cat);

                return 0;
        }

        Explicação:

        Hereditariedade: Dog e Cat podem ser vistas como "subclasses" de 
        Animal, cada uma implementando seu próprio comportamento de speak.
        Polimorfismo: A função animal_speak pode chamar speak em qualquer 
        Animal, independentemente de ser um Dog ou Cat, permitindo que 
        diferentes tipos de animais sejam tratados de forma uniforme.

5. Coesão e Acoplamento

        Conceito:
                Coesão: Refere-se ao quão bem os componentes dentro de um 
                módulo estão relacionados. Um módulo altamente coeso realiza 
                uma única tarefa ou responsabilidade.

                Acoplamento: Refere-se ao grau de dependência entre módulos. 
                Módulos com baixo acoplamento dependem pouco um do outro, o
                que facilita a manutenção e a evolução do sistema.

        Exemplo:
        Vamos comparar dois exemplos: um com baixa coesão e alto acoplamento,
         e outro com alta coesão e baixo acoplamento.

        Baixa Coesão e Alto Acoplamento:

        c

        #include <stdio.h>
        #include <stdlib.h>

        // Função que mistura lógica de IO e lógica de cálculo
        void process_data() {
                int data = 10;
                data *= 2;  // Lógica de cálculo
                printf("Processed data: %d\n", data);  // Lógica de IO
        }

        int main() {
                process_data();
                return 0;
        }

        Alta Coesão e Baixo Acoplamento:

        #include <stdio.h>
        #include <stdlib.h>

        // Função com responsabilidade única: calcular um valor
        int calculate_data(int value) {
                return value * 2;  // Lógica de cálculo
        }

        // Função com responsabilidade única: exibir um valor
        void display_data(int data) {
                printf("Processed data: %d\n", data);  // Lógica de IO
        }

        int main() {
                int value = 10;
                int result = calculate_data(value);  // Função de cálculo
                display_data(result);  // Função de exibição
                return 0;
        }
        