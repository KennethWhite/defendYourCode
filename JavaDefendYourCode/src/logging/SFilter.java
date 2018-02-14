package logging;

import java.util.logging.Filter;
import java.util.logging.Level;
import java.util.logging.LogRecord;


public class SFilter implements Filter {
        private Level level;

        SFilter(Level var){
            if(var == null){
                throw new IllegalArgumentException("Level param null on call to SFilter CTOR");
            }
            this.level = var;
        }

        public void updateFilter(Level in){
            if(in == null){
                throw new IllegalArgumentException("Level param null on call to updateFilter");
            }
            this.level = in;
        }

        @Override
        public boolean isLoggable(LogRecord record) {
                return record.getLevel().intValue() >= this.level.intValue();
        }
    }


