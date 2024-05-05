using practice_4;
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

namespace test_wpf
{
    /// <summary>
    /// Логика взаимодействия для AllMakersInfo.xaml
    /// </summary>
    public partial class AllMakersInfo : Window
    {
        public AllMakersInfo()
        {
            InitializeComponent();
            List<Shoe> shoes = MainWindow.dataBase.Shoes.ToList();
            Dictionary<string, HashSet<string>> models = new Dictionary<string, HashSet<string>>();
            Dictionary<string, int> pairs = new Dictionary<string, int>();
            foreach (Shoe shoe in shoes)
            {
                if (!models.ContainsKey(shoe.Maker))
                {
                    models[shoe.Maker] = new HashSet<string> { shoe.Model };
                }
                else
                {
                    models[shoe.Maker].Add(shoe.Model);
                }

                if (!pairs.ContainsKey(shoe.Maker))
                {
                    pairs[shoe.Maker] = shoe.Amount;
                }
                else
                {
                    pairs[shoe.Maker] += shoe.Amount;
                }
            }
            foreach (var maker in models)
            {
                AddShoeToListView(maker.Key, models[maker.Key].Count, pairs[maker.Key]);
            }
        }

        public void AddShoeToListView(string maker, int models, int pairs)
        {
            ListViewItem listViewItem = new ListViewItem();
            listViewItem.IsEnabled = false;
            Grid grid = new Grid();
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });
            grid.ColumnDefinitions.Add(new ColumnDefinition { Width = new GridLength(1, GridUnitType.Star) });

            TextBlock textBlock1 = new TextBlock { Text = maker, Margin = new Thickness(5) };
            Grid.SetColumn(textBlock1, 0);
            grid.Children.Add(textBlock1);

            TextBlock textBlock2 = new TextBlock { Text = models.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock2, 1);
            grid.Children.Add(textBlock2);

            TextBlock textBlock3 = new TextBlock { Text = pairs.ToString(), Margin = new Thickness(5) };
            Grid.SetColumn(textBlock3, 2);
            grid.Children.Add(textBlock3);

            listViewItem.Content = grid;

            ShoesItems.Items.Add(listViewItem);
        }
    }
}
