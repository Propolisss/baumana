using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Media.Media3D;

namespace practice_4
{
    public class Shoe
    {
        public int id { get; set; }
        private string model;
        private string maker;
        private int size;
        private int amount;

        public string Model
        {
            get { return model; }
            set { model = value; }
        }

        public string Maker
        {
            get { return maker; }
            set { maker = value; }
        }

        public int Size
        {
            get { return size; }
            set { size = value; }
        }
        public int Amount
        {
            get { return amount; }
            set { amount = value; }
        }

        public Shoe() { }

        public Shoe(string model, string maker, int size, int amount)
        {
            this.model = model;
            this.maker = maker;
            this.size = size;
            this.amount = amount;
        }
    }
}
