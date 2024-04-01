#include <list>
#include <string>
#include "TextBuffer.hpp"

    TextBuffer::TextBuffer() : row(1), column(0), index(0) {
        cursor = data.end();
    }

    bool TextBuffer::forward(){
        if(cursor == data.end()){
            return false;
        }
        if(*cursor == '\n'){
            column = 0;
            ++row;
        }
        else{
            ++column;
        }
        ++cursor;
        ++index;
        return true;
    }

    bool TextBuffer::backward(){
        if(cursor == data.begin()){
            return false;
        }
        --cursor;
        if(*cursor == '\n'){
            column = compute_column();
            --row;
            --index;

        }
        else{
            --index;
            --column;
        }
        return true;
    }
  
    void TextBuffer::insert(char c){
        if(cursor == data.end()){
            insert(c);
        }
        else{
            insert(c);
            ++index;
            ++column;
        }
    }

    bool TextBuffer::remove() { // NOt sure about indexing
        if(cursor == data.end()){
            return false;
        }
        ++cursor;
        if(cursor == data.end()){
            --cursor;
            data.erase(cursor);
            cursor = data.end();
        }
        else{
            --cursor;
            data.erase(cursor);
        }
        return true;
    }

    void TextBuffer::move_to_row_start(){
        column = 0;
        if (row == 1){
            cursor = data.begin();
            index = 0;
        }
        else{
            while(*cursor != '\n'){
                --cursor;
                --index;
            }
            ++cursor;
            ++index;
        }
    }

    void TextBuffer::move_to_row_end() {
        while(*cursor != '\n' && cursor != data.end()){
            forward();
        }
    }
    
    void TextBuffer::move_to_column(int new_column) {
        if(new_column >= compute_column()){ // Look at = to
            move_to_row_end();
            column = compute_column();
        }
        else{
            while(new_column != column){
                if(new_column > column){
                    forward();
                }
                else{
                    backward();
                }
            }
        }
    }

    bool TextBuffer::up() {
        int currentRow = row;
        int goalCol = column;
        if(row == 1){
            return false;
        }
        while(currentRow == row){
            backward();
        }
        if(compute_column() >= goalCol){
            return true;
        }
        else{
            while(goalCol > column){
                backward();
            }
            return true;
        }
    }


    bool TextBuffer::down(){
        List<char>::Iterator make = cursor;
        int currentRow = row;
        int goalCol = column;

        while(*make != '\n' && make != data.end()){
            ++make;
        }
        if(*make != '\n'){
            ;
            return false;
        }
        else{
            while(row == currentRow){
                forward();
            }
            while(goalCol > column){
                forward();
            }
            return true;    
        }
    }

    bool TextBuffer::is_at_end() const{
        return (cursor == data.end());
    }

    char TextBuffer::data_at_cursor() const{
        return(*cursor);
    }

    int TextBuffer::get_row() const{
        return row;
    }

    int TextBuffer::get_column() const{
        return column;
    }

    int TextBuffer::get_index() const{
        return index;
    }

    int TextBuffer::size() const{
        return(data.size()); 
    }

    std::string TextBuffer::stringify() const{
        return std::string(data.begin(), data.end());
    }

    int TextBuffer::compute_column() const{
        int tracker = 1; // I think this needs a one but could try 0 if not working

        List<char>::Iterator make = cursor;

        while(*make != '\n' && make != data.end()){
            ++make;
        }
        while(*make != '\n' && make != data.begin()){
            --make;
            ++tracker;
        }
        return tracker;
    }