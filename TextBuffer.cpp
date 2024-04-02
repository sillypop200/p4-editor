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
            ++cursor;
            ++row;
            ++index;
            column = 0;

        }
        else{
            ++column;
            ++cursor;
            ++index;
        }
        return true;
    }

    bool TextBuffer::backward(){
        if(cursor == data.begin()){
            return false;
        }
        if(column == 0){
            --row;
            --cursor;
            column = compute_column();
            --index;
        }
        else{
            --index;
            --column;
            --cursor;
        }
        return true;
    }
  
    void TextBuffer::insert(char c){
        if(cursor == data.end() || data.empty()){
            data.push_back(c);
        }
        else{
            data.insert(cursor,c);
        }
        ++index;
        if (c == '\n'){
            column = 0 ; 
            ++row;
        } else {++column;}
    }

    bool TextBuffer::remove() { // NOt sure about indexing
        if(cursor == data.end()){
            return false;
        }
        ++cursor;
        if(cursor == data.end()){
            --cursor;
            cursor = data.erase(cursor);
        }
        else{
            --cursor;
            cursor = data.erase(cursor);
        }
        return true;
    }

    void TextBuffer::move_to_row_start(){
            if (row == 1){
                while(cursor != data.begin()){
                    backward();
                }
            }
            else{
                int j = column;
                for (int i = 0; i < j; ++i){
                    backward();
                }
               
            }

    }
    void TextBuffer::move_to_row_end() {
        while(cursor != data.end() && *cursor != '\n'){
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
        int turtle = compute_column();
        if(turtle <= goalCol){
            return true;
        }
        else{
            while(goalCol < column){
                backward();
            }
            return true;
        }
    }


    bool TextBuffer::down(){
        Iterator make = cursor;
        int currentRow = row;
        int goalCol = column;

        while(make != data.end() && *make != '\n'){
            ++make;
        }
        if(make == data.end()){
            return false;
        }
        else{
            while(row == currentRow){
                forward();
            }
            int turtle = compute_column();
            if(goalCol > turtle){
                for(int i = 0; i < turtle; i++){
                    forward();
                }
            }
            else{
                while(goalCol != column){
                    forward();
                }    
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
        int tracker = 0; // I think this needs a one but could try 0 if not working

        Iterator make = cursor;

        while(make != data.end() && *make != '\n'){
            ++make;
        }
              --make;
        while(*make != '\n' && make != data.begin()){//its not counting the beginning 
            --make;
            ++tracker;
        }
        if(make==data.begin()){
            ++tracker;
        }
        return tracker;
    }