# Philosophers Project (Philo)

## Objetivo do Projeto
O projeto **Philosophers** simula o clássico problema dos filósofos, em que um grupo de filósofos compartilha garfos e alterna entre pensar, comer e dormir. O objetivo é implementar uma solução que:

- Evite **deadlocks** e **race conditions**.
- Monitore a **morte de filósofos** quando não comem a tempo.
- Permita a definição de um **número de refeições** opcionais após o qual o programa encerra.
- Controle a **impressão das ações** de forma sincronizada com timestamps.

---

## Estruturas Principais

### `t_philo`
Representa cada filósofo.
- `id`: identificador do filósofo.
- `meals_eaten`: contador de refeições realizadas.
- `last_meal_time`: timestamp da última refeição.
- `thread_id`: ID da thread do filósofo.
- `left_fork` / `right_fork`: ponteiros para mutexes que representam garfos.
- `table`: ponteiro para a mesa compartilhada.

### `t_table`
Representa a mesa e os recursos compartilhados.
- `number_of_philosophers`: quantidade de filósofos.
- `time_to_die`, `time_to_eat`, `time_to_sleep`: tempos em milissegundos.
- `must_eat_count`: número de refeições opcionais para encerrar a simulação.
- `forks`: array de mutexes que representam os garfos.
- `print_mutex`: mutex para proteger impressões.
- `someone_died`: flag que indica se algum filósofo morreu.
- `philo`: array de todos os filósofos.

---

## Fluxo do Programa

1. Inicialização da mesa (`t_table`) e dos filósofos (`t_philo`).
2. Criação de uma thread para cada filósofo, que executa `philosopher_routine`.
3. Cada filósofo:
   - Pega os garfos (com ordem alternada para pares/ímpares para evitar deadlock).
   - Come, atualizando `last_meal_time`.
   - Larga os garfos.
   - Dorme.
   - Pensa.
4. Uma **thread monitor** verifica constantemente:
   - Se algum filósofo morreu (`time_to_die`).
   - Se todos comeram o número mínimo de refeições (opcional).
5. O programa encerra quando:
   - Algum filósofo morre, ou
   - Todos os filósofos atingem `must_eat_count` (se definido).

---

## Funções Principais

### `philosopher_routine`
Thread principal de cada filósofo. Executa em loop: comer → dormir → pensar, até que a simulação termine.

### `take_forks` e `drop_forks`
Controlam o acesso aos garfos usando mutexes para evitar **race conditions**.

### `eat`, `philo_sleep`, `think`
Funções que executam ações de cada filósofo, atualizando o estado e imprimindo mensagens sincronizadas.

### `monitor`
Thread que verifica continuamente se algum filósofo morreu ou se todos completaram suas refeições.

### `print_status`
Imprime mensagens com timestamp relativo ao início da simulação, usando mutex para evitar conflitos.

---

## Uso

Compilar:

```bash
make
