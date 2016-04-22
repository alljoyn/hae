package org.alljoyn.smartspaces;

/**
 * Created by jiny1u on 16. 5. 2.
 */


public enum Bool implements EnumBase<Boolean> {
    True(true) {
        @Override
        public String toString() {
            return "true";
        }
    },
    False(false) {
        @Override
        public String toString() {
            return "false";
        }
    };
    private boolean value;
    private Bool(boolean value) {
        this.value = value;
    }
    public Boolean toValue() {
        return value;
    }
}
