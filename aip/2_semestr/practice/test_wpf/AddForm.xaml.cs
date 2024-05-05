using System;
using System.Collections.Generic;
using System.Linq;
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

namespace practice_4
{
    /// <summary>
    /// Логика взаимодействия для AddForm.xaml
    /// </summary>
    public partial class AddForm : Window
    {
        public AddForm()
        {
            InitializeComponent();
            ModelTextBox.Focus();
        }

        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            //var y = MainWindow.dataBase.Shoes.Count();
            //MainWindow.dataBase.Shoes.RemoveRange(MainWindow.dataBase.Shoes);
            //MainWindow.dataBase.SaveChanges();
            //var x = MainWindow.dataBase.Shoes.Count();
            try
            {
                Shoe tempShoe = new Shoe(ModelTextBox.Text, MakerTextBox.Text, Convert.ToInt32(SizeTextBox.Text), Convert.ToInt32(AmountTextBox.Text));
                if (tempShoe.Model.Length == 0 || tempShoe.Maker.Length == 0)
                {
                    throw new Exception("empty data");
                }
                Shoe t = MainWindow.dataBase.Shoes.SingleOrDefault(s => s.Model == tempShoe.Model &&
                    s.Maker == tempShoe.Maker && s.Size == tempShoe.Size && s.Amount == tempShoe.Amount);
                if (t != null)
                {
                    MessageBox.Show("Данная модель уже существует", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                    return;
                }
                MainWindow.dataBase.Shoes.Add(tempShoe);
                MainWindow.dataBase.SaveChanges();
                MainWindow mainWindow = Application.Current.Windows.OfType<MainWindow>().FirstOrDefault();
                mainWindow.AddShoeToListView(tempShoe);
                ModelTextBox.Text = "";
                MakerTextBox.Text = "";
                SizeTextBox.Text = "";
                AmountTextBox.Text = "";
                ModelTextBox.Focus();
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
