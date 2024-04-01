#include <list>
#include <string>
#include "TextBuffer.hpp"


    TextBuffer::TextBuffer() : row(1), column(0), index(0) {
    cursor = data.begin();
    }

    bool TextBuffer::forward(){
        if(*cursor == '\n   '){
            return false;
        }
        ++cursor;
        ++index;
        ++column;
        return true;
    }

    bool TextBuffer::backward(){
        if(cursor == data.begin()){
            return false;
        }
        --cursor;
        if(*cursor == '\n'){
            ++cursor;
            return false;
        }
        --index;
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

    bool TextBuffer::remove() {
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
            ++cursor;
            ++index;
        }
    }
    
    void TextBuffer::move_to_column(int new_column) {
    }

    bool TextBuffer::up() {
        assert(true);
    }

    bool TextBuffer::down(){
        assert(true);
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
        assert(true);
    }

    int TextBuffer::compute_column() const{
        assert(true);
    }