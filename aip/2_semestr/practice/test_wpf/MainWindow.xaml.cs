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
using System.Windows.Navigation;
using System.Windows.Shapes;
using test_wpf;

namespace practice_4
{
    public partial class MainWindow : Window
    {
        static internal DataBase dataBase;
        public MainWindow()
        {
            InitializeComponent();
            List<Shoe> shoes = dataBase.Shoes.ToList();
            foreach (Shoe shoe in shoes)
            {
                AddShoeToListView(shoe);
            }
        }

        static MainWindow()
        {
            dataBase = new DataBase();
        }

        public void AddShoeToListView(Shoe shoe)
        {
            ListViewItem listViewItem = new ListViewItem();
            Grid grid = new Grid();
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });

            TextBlock textBlock1 = new TextBlock { Text = shoe.Model, Margin = new Thickness(5) };
            Grid.SetColumn(textBlock1, 0);
            grid.Children.Add(textBlock1);

            TextBlock textBlock2 = new TextBlock { Text = shoe.Maker, Margin = new Thickness(5) };
            Grid.SetColumn(textBlock2, 1);
            grid.Children.Add(textBlock2);

            TextBlock textBlock3 = new TextBlock { Text = shoe.Size.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock3, 2);
            grid.Children.Add(textBlock3);

            TextBlock textBlock4 = new TextBlock { Text = shoe.Amount.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock4, 3);
            grid.Children.Add(textBlock4);

            listViewItem.Content = grid;

            ShoesItems.Items.Add(listViewItem);
        }

        private void AddButton_Click(object sender, RoutedEventArgs e)
        {
            AddForm addForm = new AddForm();
            addForm.ShowDialog();
        }


        private void DeleteButton_Click(object sender, RoutedEventArgs e)
        {
            var selectedItems = ShoesItems.SelectedItems;
            if (selectedItems.Count == 0)
            {
                MessageBox.Show("Не выбраны модели для удаления", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            for (int i = selectedItems.Count - 1; i >= 0; i--)
            {
                if (selectedItems[i] is ListViewItem item)
                {
                    if (item.Content is Grid grid)
                    {
                        TextBlock textBlock1 = grid.Children[0] as TextBlock;
                        TextBlock textBlock2 = grid.Children[1] as TextBlock;
                        TextBlock textBlock3 = grid.Children[2] as TextBlock;
                        TextBlock textBlock4 = grid.Children[3] as TextBlock;

                        string model = textBlock1.Text;
                        string maker = textBlock2.Text;
                        int size = int.Parse(textBlock3.Text);
                        int amount = int.Parse(textBlock4.Text);

                        Shoe shoe = dataBase.Shoes.FirstOrDefault(s => s.Model == model && s.Maker == maker
                        && s.Size == size && s.Amount == amount);
                        if (shoe != null)
                        {
                            dataBase.Shoes.Remove(shoe);
                            dataBase.SaveChanges();
                        }
                    }
                }
                ShoesItems.Items.Remove(selectedItems[i]);
            }
        }

        private void FindButton_Click(object sender, RoutedEventArgs e)
        {
            FindForm findForm = new FindForm();
            findForm.ShowDialog();
        }

        private void MakerInfoButton_Click(object sender, RoutedEventArgs e)
        {
            if (MakerTextBox.Text.Length == 0)
            {
                MessageBox.Show("Введите производителя", "Ошибка", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            List<Shoe> tempShoes = MainWindow.dataBase.Shoes.Where(s => s.Maker == MakerTextBox.Text).ToList();
            if (tempShoes.Count == 0)
            {
                MessageBox.Show("Данного производителя нет в базе данных", "Сообщение", MessageBoxButton.OK, MessageBoxImage.Error);
                return;
            }
            MakerInfo makerInfo = new MakerInfo(MakerTextBox.Text);
            makerInfo.ShowDialog();

        }

        private void AllMakersInfoButton_Click(object sender, RoutedEventArgs e)
        {
            AllMakersInfo allMakersInfo = new AllMakersInfo();
            allMakersInfo.ShowDialog();
        }
    }
}
