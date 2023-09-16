#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    arr_size=0;
    ui->setupUi(this);
    ui->tableWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget->setEditTriggers(QHeaderView::NoEditTriggers);
    ui->tableWidget_2->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget_2->setEditTriggers(QHeaderView::NoEditTriggers);
    ui->tableWidget_3->setSelectionMode(QAbstractItemView::NoSelection);
    ui->tableWidget_3->setEditTriggers(QHeaderView::NoEditTriggers);
    ui->Add_button->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::sort(Student *arr, int size)
{
    for(int i = 1; i < size; i++)
    {
        int j = i - 1;

        while(j >= 0 && arr[j].fio[0] > arr[j + 1].fio[0])
        {
            std::swap(arr[j], arr[j + 1]);
            j--;
        }
    }
}

void MainWindow::on_Open_file_button_clicked()
{
    fileName = QFileDialog::getOpenFileName(this,"Choose file","start.txt"," Текстовые файлы (*txt)");
    file.setFileName(fileName);

    if(flag)
    {
        file.open(QIODevice::ReadWrite);

        for(int i=0;i<arr_size;++i)
        {
            arr[i].fio.clear();
            arr[i].marks.clear();
        }

        arr_size=0;

        for(int i=0;i<size;++i)
        {
            list.pop_front();
        }

        size=0;

        if(file.isOpen())
        {
            int i=0;
            QTextStream in(&file);
            QStringList str;
            QString str2;

            while(!in.atEnd())
            {
                str = QString(in.readLine()).split("\r");
                while(i<str.size())
                {
                    str2.push_back(str[i]);
                    ++i;
                }

                i=0;
                Student buffer;
                buffer.fio = str2;
                str.clear();
                str2.clear();
                str = QString(in.readLine()).split("\r");

                while(i<str.size())
                {
                    str2.push_back(str[i]);
                    ++i;
                }

                i=0;
                buffer.marks=str2;
                str.clear();
                str = QString(in.readLine()).split("\r");
                if(str[0] != "no")
                list.push_back(buffer);
                str.clear();
                str2.clear();
                ++size;
            }
        }

        //average mark
        float buffer;
        average_mark=0;
        int j=0;

        for(Node* ptr=list.head; ptr!=nullptr; ptr=ptr->next)
        {
            buffer = list[j]->data.marks[0].digitValue() + list[j]->data.marks[2].digitValue() + list[j]->data.marks[4].digitValue() + list[j]->data.marks[6].digitValue() + list[j]->data.marks[8].digitValue();
            average_mark+=buffer;
            ++j;
        }

        average_mark /= size;
        average_mark /= 5;
        buffer=0;
        j=0;
        ui->tableWidget_3->clear();
        QStringList header;
        header<<tr("fio")<<tr("marks");
        ui->tableWidget_3->setHorizontalHeaderLabels(header);
        res=0;
        memory.clear();

        for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
        {
           buffer = list[j]->data.marks[0].digitValue() + list[j]->data.marks[2].digitValue() + list[j]->data.marks[4].digitValue() + list[j]->data.marks[6].digitValue() + list[j]->data.marks[8].digitValue();
           buffer/=5;
         arr[j].fio=list[j]->data.fio;
         arr[j].marks=list[j]->data.marks;
         ++arr_size;
           if(buffer>average_mark)
           {
               memory+=list[j]->data.fio;
               memory+=' ';
               memory+=list[j]->data.marks;
               memory+=' ';
               ui->tableWidget_3->setItem(res,0,new QTableWidgetItem(list[j]->data.fio));
                        ui->tableWidget_3->setItem(res,1,new QTableWidgetItem(list[j]->data.marks));
                        ++res;
           }
           ++j;
        }
          sort(arr,arr_size);
      }
}

void MainWindow::on_Add_button_clicked()
{
    flag=1;
    int j=0;
    int spaces = 0;
    int nums=0;
    QString str=ui->lineEdit->text();
    ui->lineEdit->clear();
    if(flag)
    {
        while(str[j]!=' ')
        {
            if(!str[j].isLetter())
            {
                flag=0;
                break;
            }
            ++j;
        }
        ++spaces;
        ++j;
        if(flag)
        {
        while(j<str.size())
        {
            if(str[j]==' ')
            {
                ++spaces;
                ++j;
                continue;
            }
            if(!str[j].isDigit())
            {
                flag=0;
                break;
            }
            else ++nums;
            ++j;
        }
        }
        if(spaces != 5 || nums != 5) flag=0;

        if(!flag)
        {
            QMessageBox::warning(this,"Error","Incorrect input");
        }
        else
        {
            QString str3=str;
            file.close();
            file.open(QIODevice::Append);
            QTextStream out(&file);
            for(int i=0;i<str3.size();++i)
                if(str3[i]==' ')
                {
                    str3[i]='\n';
                    break;
                }
            str3.push_front('\n');
            str3+="\nyes";
            out<<str3;
        j=0;
        QString str2;
        Student buffer;
        while(str[j]!=' ')
         {
            str2.push_back(str[j]);
            ++j;
         }
        ++j;
        buffer.fio=str2;
        str2.clear();
        while(j<str.size())
         {
            str2.push_back(str[j]);
            ++j;
         }
        buffer.marks=str2;
        str2.clear();
        list.push_back(buffer);
        arr[arr_size].fio=buffer.fio;
        arr[arr_size].marks=buffer.marks;
        ++arr_size;
        }
    }
    //average mark
    float buffer;
    average_mark=0;
    int i=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[i]->data.marks[0].digitValue() + list[i]->data.marks[2].digitValue() + list[i]->data.marks[4].digitValue() + list[i]->data.marks[6].digitValue() + list[i]->data.marks[8].digitValue();
        average_mark+=buffer;
        ++i;
    }

    ++size;
    average_mark /= size;
    average_mark /= 5;
    buffer=0;
    j=0;
    ui->tableWidget_3->clear();
    QStringList header;
    header<<tr("fio")<<tr("marks");
    ui->tableWidget_3->setHorizontalHeaderLabels(header);
    res=0;
    memory.clear();

    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[j]->data.marks[0].digitValue() + list[j]->data.marks[2].digitValue() + list[j]->data.marks[4].digitValue() + list[j]->data.marks[6].digitValue() + list[j]->data.marks[8].digitValue();
       buffer/=5;
       if(buffer>average_mark)
       {
           memory+=list[j]->data.fio;
           memory+=' ';
           memory+=list[j]->data.marks;
           memory+=' ';
           ui->tableWidget_3->setItem(res,0,new QTableWidgetItem(list[j]->data.fio));
                    ui->tableWidget_3->setItem(res,1,new QTableWidgetItem(list[j]->data.marks));
                    ++res;
       }
       ++j;
    }   
    sort(arr,arr_size);

}

void MainWindow::on_show_list_button_clicked()
{
    ui->tableWidget->clear();
    QStringList header;
      header<<tr("fio")<<tr("marks");
    ui->tableWidget->setHorizontalHeaderLabels(header);
    for(int i=0;i<arr_size;++i)
    {
      ui->tableWidget->setItem(i,0,new QTableWidgetItem(arr[i].fio));
               ui->tableWidget->setItem(i,1,new QTableWidgetItem(arr[i].marks));
    }
}

void MainWindow::on_find_button_clicked()
{
    QString find=ui->lineEdit_2->text();
    ui->lineEdit_2->clear();
    int i=0;
    int cell=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        if(find==list[i]->data.fio||find==list[i]->data.marks)
        {
          ui->tableWidget_2->setItem(cell,0,new QTableWidgetItem(list[i]->data.fio));
          ui->tableWidget_2->setItem(cell,1,new QTableWidgetItem(list[i]->data.marks));
          ++cell;
        }
        ++i;
    }
    if(!cell) QMessageBox::warning(this,"","ничего не найдено");
}

void MainWindow::on_Add_in_file_button_clicked()
{
    fileName1 = QFileDialog::getOpenFileName(this,"Выберите файл","D:/lab2_1"," Текстовые файлы (*txt)");
    file1.setFileName(fileName1);

        file1.open(QIODevice::WriteOnly);
        QTextStream out(&file1);
        out<<memory;
        file1.close();
}

void MainWindow::on_radioButton_toggled(bool checked)
{
    if(checked) ui->Add_button->setEnabled(true);
            else ui->Add_button->setEnabled(false);
}


void MainWindow::on_delete_button_clicked()
{
    QString str=ui->lineEdit_3->text();
    int i=0;
    int index=0;
    bool a=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        if(list[i]->data.fio==str)
        {
            list.erase(i);
            a=1;
            break;
        }
        ++i;
    }
    if(a)
    {
   for(int i=0;i<arr_size;++i)
   {
       if(arr[i].fio==str)index=i;
   }
   for(index;index<arr_size-1;++index)
   {
       arr[index].fio=arr[index+1].fio;
       arr[index].marks=arr[index+1].marks;
   }
   --arr_size;
   --size;
   sort(arr,arr_size);
    }

    float buffer;
    average_mark=0;
     i=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[i]->data.marks[0].digitValue() + list[i]->data.marks[2].digitValue() + list[i]->data.marks[4].digitValue() + list[i]->data.marks[6].digitValue() + list[i]->data.marks[8].digitValue();
        average_mark+=buffer;
        ++i;
    }
    average_mark/=size;
    average_mark/=5;
    buffer=0;
    int j=0;
      ui->tableWidget_3->clear();
      QStringList header;
        header<<tr("fio")<<tr("marks");
      ui->tableWidget_3->setHorizontalHeaderLabels(header);
      res=0;
      memory.clear();
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[j]->data.marks[0].digitValue() + list[j]->data.marks[2].digitValue() + list[j]->data.marks[4].digitValue() + list[j]->data.marks[6].digitValue() + list[j]->data.marks[8].digitValue();
       buffer/=5;
       if(buffer>average_mark)
       {
           memory+=list[j]->data.fio;
           memory+=' ';
           memory+=list[j]->data.marks;
           memory+=' ';
           ui->tableWidget_3->setItem(res,0,new QTableWidgetItem(list[j]->data.fio));
                    ui->tableWidget_3->setItem(res,1,new QTableWidgetItem(list[j]->data.marks));
                    ++res;
       }
       ++j;
    }
}

void MainWindow::on_Change_clicked()
{
    QString str=ui->lineEdit_4->text();
    QString change=ui->lineEdit_5->text();
    ui->lineEdit_4->clear();
    ui->lineEdit_5->clear();
    int i=0;
    int index=0;
    bool a=0;
    bool flag=0;
        if(change.size()==0)flag=1;
        if(!flag)
        {
    if(str[0].isLetter())
    {
        for(int i=0;i<change.size();++i)
        {
            if(!change[i].isLetter())
            {
                flag=1;
                break;
            }
        }
    }
    else
    {
        if(change.size()!=9)flag=1;
        if(!flag)
        {
if((!change[0].isDigit()||change[0].digitValue()>5||change[0].digitValue()<1)||(!change[2].isDigit()||change[2].digitValue()>5||change[2].digitValue()<1)||(!change[4].isDigit()||change[4].digitValue()>5||change[4].digitValue()<1)||(!change[6].isDigit()||change[6].digitValue()>5||change[6].digitValue()<1)||(!change[8].isDigit()||change[8].digitValue()>5||change[8].digitValue()<1))flag=1;
if(change[1]!=' '||change[3]!=' '||change[5]!=' '||change[7]!=' ')flag=1;
        }
    }
  }
  if(flag) QMessageBox::warning(this,"Error","неверный ввод");
if(!flag)
{
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        if(list[i]->data.fio==str)
        {
            list[i]->data.fio=change;
            a=1;
            break;
        }
        if(list[i]->data.marks==str)
        {
            list[i]->data.marks=change;
            a=1;
            break;
        }
        ++i;
    }
    if(a)
    {
   for(int i=0;i<arr_size;++i)
   {
       if(arr[i].fio==str)
       {
           arr[i].fio=change;
           break;
       }
       if(arr[i].marks==str)
       {
           arr[i].marks=change;
           break;
       }
   }
   sort(arr,arr_size);
    }
    float buffer;
    average_mark=0;
     i=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[i]->data.marks[0].digitValue() + list[i]->data.marks[2].digitValue() + list[i]->data.marks[4].digitValue() + list[i]->data.marks[6].digitValue() + list[i]->data.marks[8].digitValue();
        average_mark+=buffer;
        ++i;
    }
    average_mark/=size;
    average_mark/=5;
    buffer=0;
    int j=0;
      ui->tableWidget_3->clear();
      QStringList header;
        header<<tr("fio")<<tr("marks");
      ui->tableWidget_3->setHorizontalHeaderLabels(header);
      res=0;
      memory.clear();
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
        buffer = list[j]->data.marks[0].digitValue() + list[j]->data.marks[2].digitValue() + list[j]->data.marks[4].digitValue() + list[j]->data.marks[6].digitValue() + list[j]->data.marks[8].digitValue();
       buffer/=5;
       if(buffer>average_mark)
       {
           memory+=list[j]->data.fio;
           memory+=' ';
           memory+=list[j]->data.marks;
           memory+=' ';
           ui->tableWidget_3->setItem(res,0,new QTableWidgetItem(list[j]->data.fio));
                    ui->tableWidget_3->setItem(res,1,new QTableWidgetItem(list[j]->data.marks));
                    ++res;
       }
       ++j;
    }
}
}

void MainWindow::on_write_in_file_clicked()
{
    file.close();
    file.open(QIODevice::WriteOnly);
    QTextStream out(&file);
    QString buffer;
    int i=0;
    for(Node* ptr=list.head;ptr!=nullptr;ptr=ptr->next)
    {
    buffer+=list[i]->data.fio;
    buffer+='\n';
    buffer+=list[i]->data.marks;
    buffer+="\nyes\n";
            ++i;
    }
    buffer.remove(buffer.size()-1,1);
    out<<buffer;
}


