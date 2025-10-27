import matplotlib.pyplot as plt
import math
from matplotlib import font_manager




def read_data(filename):
  x = []
  y = []
  try:
    with open(filename, 'r') as f:
      for line in f:
        try:
          xi, yi = map(float, line.strip().split())  # Преобразуем в float
          x.append(xi)
          y.append(yi)
        except ValueError:
          print(f"Ошибка при чтении строки: {line.strip()}.  Пропускаю строку.")
  except FileNotFoundError:
    print(f"Файл не найден: {filename}")
    return [], []
  return x, y



def draw(x_heap, y_heap, x_quick, y_quick, xlabel, ylabel, savepath, title):
  if (x_heap and y_heap) and (x_quick and y_quick):  
    plt.plot(x_heap, y_heap, marker='o', linestyle='-', color='r', label='HeapSort')
    plt.plot(x_quick, y_quick, marker='o', linestyle='-', color='b', label='QuickSort') 
    plt.xlabel(xlabel, fontweight='bold', labelpad=5, fontsize=25)
    plt.ylabel(ylabel, fontweight='bold', labelpad=5, fontsize=25)
    plt.title(title, fontweight='bold', fontsize=30)

    plt.xticks(fontsize=23, fontweight='bold')
    plt.yticks(fontsize=23, fontweight='bold')

    plt.grid(True)  # Добавляет сетку
    font_prop = font_manager.FontProperties(weight='bold', size=25)
    plt.legend(loc='upper left', bbox_to_anchor=(0, -0.05), prop=font_prop)

    plt.savefig(savepath) # Сохраняет график в файл

    plt.subplots_adjust(bottom=0.2)

    plt.show()  # Показывает график
  else:
    print("Невозможно построить график: данные отсутствуют.")


def divide_lists(numerator_list, denominator_list):
    """
    Делит элементы numerator_list на соответствующие элементы denominator_list.

    Обрабатывает деление на ноль, возвращая NaN (Not a Number) 
    или 0 в зависимости от вашего предпочтения.
    """
    results = []
    
    # Использование zip() для итерации по двум спискам одновременно
    for numerator, denominator in zip(numerator_list, denominator_list):
        if denominator == 0 or denominator == 1:
            # Безопасная обработка деления на ноль. 
            # NaN (Not a Number) - стандартный способ показать невалидный результат
            results.append(numerator) 
            # Если вы предпочитаете 0: results.append(0)
        else:
            # Выполняем деление
            results.append(numerator / (denominator * math.log2(denominator)))
            
    return results


print('Select the experiment:\n')
print('(1) q = 1; w = 10^9; n = 1, ... , 10^6 + 1 with step = 10^4\n')
print('(2) q = 1; w = 1, ... , 100 with step 1; n = 10^6\n')
exp = input('> ')
print('Default(0) or normalized(1)?\n')
norm = input('> ')

if exp == '1':
  filename1 = '../data/file_random_heap_sort1.txt'
  filename2 = '../data/file_random_quick_sort1.txt'
  filename3 = '../data/file_non_decrease_heap_sort1.txt'
  filename4 = '../data/file_non_decrease_quick_sort1.txt'
  filename5 = '../data/file_non_increase_heap_sort1.txt'
  filename6 = '../data/file_non_increase_quick_sort1.txt'
if exp == '2':
  filename1 = '../data/file_random_heap_sort2.txt'
  filename2 = '../data/file_random_quick_sort2.txt'
  filename3 = '../data/file_non_decrease_heap_sort2.txt'
  filename4 = '../data/file_non_decrease_quick_sort2.txt'
  filename5 = '../data/file_non_increase_heap_sort2.txt'
  filename6 = '../data/file_non_increase_quick_sort2.txt'

x1, y1 = read_data(filename1)
x2, y2 = read_data(filename2)
x3, y3 = read_data(filename3)
x4, y4 = read_data(filename4)
x5, y5 = read_data(filename5)
x6, y6 = read_data(filename6)

ylabel = 'Time'
if norm == '1':
  y1 = divide_lists(y1, x1)
  y2 = divide_lists(y2, x2)
  y3 = divide_lists(y3, x3)
  y4 = divide_lists(y4, x4)
  y5 = divide_lists(y5, x5)
  y6 = divide_lists(y6, x6)
  ylabel = 'Time / nlogn'

draw(x1, y1, x2, y2, 'n', ylabel, 'random.png', 'Random Filling')
draw(x3, y3, x4, y4, 'n', ylabel, 'non_decrease.png', 'Non-Decrease Filling')
draw(x5, y5, x6, y6, 'n', ylabel, 'non_increase.png', 'Non-Increase Filling')