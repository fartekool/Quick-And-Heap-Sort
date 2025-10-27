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
          xi, yi = map(float, line.strip().split()) # Преобразуем в float
          if (xi == 1):
            yi  = yi / (xi)
          else:
            yi  = yi / (xi * math.log2(xi))
          x.append(xi)
          y.append(yi)
        except ValueError:
          print(f"Ошибка при чтении строки: {line.strip()}.  Пропускаю строку.")
  except FileNotFoundError:
    print(f"Файл не найден: {filename}")
    return [], []
  return x, y



def draw(x_heap, y_heap, x_quick, y_quick, xlabel, ylabel, norm, savepath, title):
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


print('Select the experiment:\n')
print('(1) q = 1; w = 10^9; n = 1, ... , 10^6 + 1 with step = 10^4\n')
print('(2) q = 1; w = 1, ... , 100 with step 1; n = 10^6\n')
exp = input('> ')
print('Default(0) or normalized(1)?\n')
norm = input('> ')


  