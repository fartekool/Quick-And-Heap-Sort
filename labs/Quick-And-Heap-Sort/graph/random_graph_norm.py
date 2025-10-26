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


filename1 = '../data/file_random_heap_sort.txt'
filename2 = '../data/file_random_quick_sort.txt'
x1, y1 = read_data(filename1)
x2, y2 = read_data(filename2)
  

if x1 and y1:  
    plt.plot(x1, y1, marker='o', linestyle='-', color='r', label='HeapSort')
    plt.plot(x2, y2, marker='o', linestyle='-', color='b', label='QuickSort') 
    plt.xlabel('n', fontweight='bold', labelpad=5, fontsize=25)
<<<<<<< HEAD
    plt.ylabel('Time/(nlogn)', fontweight='bold', labelpad=5, fontsize=25)
=======
    plt.ylabel('Time/n', fontweight='bold', labelpad=5, fontsize=25)
>>>>>>> b1fccd400925674cea0df64df20c561d1f242a29
    plt.title('Random Filling', fontweight='bold', fontsize=30)

    plt.xticks(fontsize=23, fontweight='bold')
    plt.yticks(fontsize=23, fontweight='bold')

    plt.grid(True)  # Добавляет сетку
    font_prop = font_manager.FontProperties(weight='bold', size=25)
    plt.legend(loc='upper left', bbox_to_anchor=(0, -0.05), prop=font_prop)

    plt.savefig('../data/random_norm.png') # Сохраняет график в файл

    plt.subplots_adjust(bottom=0.2)

    plt.show()  # Показывает график
else:
    print("Невозможно построить график: данные отсутствуют.")