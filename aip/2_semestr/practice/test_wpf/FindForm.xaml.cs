using practice_4;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.Remoting.Contexts;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace test_wpf
{
    /// <summary>
    /// Логика взаимодействия для FindForm.xaml
    /// </summary>
    public partial class FindForm : Window
    {
        public FindForm()
        {
            InitializeComponent();
            ModelTextBox.Focus();
        }

        private void FindButton_Click(object sender, RoutedEventArgs e)
        {
            //var y = MainWindow.dataBase.Shoes.Count();
            //MainWindow.dataBase.Shoes.RemoveRange(MainWindow.dataBase.Shoes);
            //MainWindow.dataBase.SaveChanges();
            //var x = MainWindow.dataBase.Shoes.Count();
            try
            {
                string modelName = ModelTextBox.Text;
                int size = int.Parse(SizeTextBox.Text);
                if (modelName.Length == 0)
                {
                    throw new Exception("empty data");
                }
                List<Shoe> tempShoes = MainWindow.dataBase.Shoes.Where(s => s.Model == modelName && s.Size == size).ToList();

                if (tempShoes.Count > 0)
                {
                    MessageBox.Show("Данная модель есть в наличии", "Сообщение", MessageBoxButton.OK, MessageBoxImage.Information);
                }
                else
                {
                    MessageBox.Show("Данной модели нет в наличии", "Сообщение", MessageBoxButton.OK, MessageBoxImage.Error);
                }
            }
            catch
            {
                MessageBox.Show("Введены некорректные данные", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
            }
        }

        private void ExitButton_Click(object sender, RoutedEventArgs e)
        {
            Close();
        }
    }
}
