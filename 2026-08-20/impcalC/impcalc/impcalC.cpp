#define CLAY_COMPATIBILITY_CPP
extern "C"{
#define CLAY_IMPLEMENTATION
#include "clay.h"
}
#include "clay/renderers/raylib/raylib.h"
#include "operations.h"
#include <string>
#include <cstring>
constexpr Clay_Color Colour_Button = { 216, 226, 236, 255 };
constexpr Clay_Color Colour_Button_Hover = { 196, 206, 216, 255 };
constexpr Clay_Color Colour_Button_Pressed = { 176, 186, 196, 255 };
constexpr Clay_Color Colour_Button_Operation = { 236, 234, 216, 255 };
constexpr Clay_Color Colour_Button_Operation_Hover = { 216, 214, 196, 255 };
constexpr Clay_Color Colour_Button_Operation_Pressed = { 196, 194, 176, 255 };
constexpr Clay_Color colour_BG = { 164, 211, 238, 255 };
constexpr Clay_Color Colour_Display_BG = { 245, 242, 225, 255 };
// --- Calculator State Engine Variables ---
static std::string displayBuffer = "0";
static double firstOperand = 0.0;
static std::string activeOperator;
static bool clearOnNextInput = false;
static bool IsKeyPressedForButton(const char* label) {
    if (strcmp(label, "0") == 0) return IsKeyPressed(KEY_ZERO)  || IsKeyPressed(KEY_KP_0);
    if (strcmp(label, "1") == 0) return IsKeyPressed(KEY_ONE)   || IsKeyPressed(KEY_KP_1);
    if (strcmp(label, "2") == 0) return IsKeyPressed(KEY_TWO)   || IsKeyPressed(KEY_KP_2);
    if (strcmp(label, "3") == 0) return IsKeyPressed(KEY_THREE) || IsKeyPressed(KEY_KP_3);
    if (strcmp(label, "4") == 0) return IsKeyPressed(KEY_FOUR)  || IsKeyPressed(KEY_KP_4);
    if (strcmp(label, "5") == 0) return IsKeyPressed(KEY_FIVE)  || IsKeyPressed(KEY_KP_5);
    if (strcmp(label, "6") == 0) return IsKeyPressed(KEY_SIX)   || IsKeyPressed(KEY_KP_6);
    if (strcmp(label, "7") == 0) return IsKeyPressed(KEY_SEVEN) || IsKeyPressed(KEY_KP_7);
    if (strcmp(label, "8") == 0) return IsKeyPressed(KEY_EIGHT) || IsKeyPressed(KEY_KP_8);
    if (strcmp(label, "9") == 0) return IsKeyPressed(KEY_NINE)  || IsKeyPressed(KEY_KP_9);
    if (strcmp(label, "+") == 0) return IsKeyPressed(KEY_KP_ADD)      || (IsKeyDown(KEY_LEFT_SHIFT) && IsKeyPressed(KEY_EQUAL));
    if (strcmp(label, "—") == 0) return IsKeyPressed(KEY_MINUS)     || IsKeyPressed(KEY_KP_SUBTRACT);
    if (strcmp(label, "X") == 0) return IsKeyPressed(KEY_KP_MULTIPLY) || IsKeyPressed(KEY_X);
    if (strcmp(label, "÷") == 0) return IsKeyPressed(KEY_KP_DIVIDE)   || IsKeyPressed(KEY_SLASH);
    if (strcmp(label, "=") == 0) return IsKeyPressed(KEY_ENTER)       || IsKeyPressed(KEY_KP_ENTER) || IsKeyPressed(KEY_EQUAL);
    if (strcmp(label, "DEL") == 0) return IsKeyPressed(KEY_BACKSPACE) || IsKeyPressed(KEY_DELETE);
    return false;
}
// Routes input tokens to strings or functions inside operations.h
static void HandleButtonInput(const std::string& token) {
    if (token == "DEL") {
        if (!displayBuffer.empty()) {
            displayBuffer.pop_back();
        }
        if (displayBuffer.empty() || displayBuffer == "-") {
            displayBuffer = "0";
        }
        return;
    }

    if (token == "+" || token == "—" || token == "X" || token == "÷") {
        firstOperand = std::stod(displayBuffer);
        activeOperator = token;
        clearOnNextInput = true;
        return;
    }

    if (token == "=") {
        if (activeOperator.empty()) return;

        int a = static_cast<int>(firstOperand);
        int b = std::stoi(displayBuffer);
        double result = 0.0;

        if (activeOperator == "+") result = add(a, b);
        if (activeOperator == "—") result = subtract(a, b);
        if (activeOperator == "X") result = multiply(a, b);
        if (activeOperator == "÷") {
            result = (b != 0) ? divide(a, b) : 0;
        }

        displayBuffer = std::to_string(result);

        if (displayBuffer.find('.') != std::string::npos) {
            while (displayBuffer.back() == '0') displayBuffer.pop_back();
            if (displayBuffer.back() == '.') displayBuffer.pop_back();}
        activeOperator = "";
        clearOnNextInput = true;
        return;}
    // Number keys input mapping
    if (clearOnNextInput) {
        displayBuffer = "";
        clearOnNextInput = false;}
    if (displayBuffer == "0") {
        displayBuffer = token;
    } else {
        displayBuffer += token;}
}
static void RenderCalculatorGrid(uint32_t fontId, int textColor) {
    static const char* gridButtons[4][4] = {
        {"1", "2", "3", "+"}, {"4", "5", "6", "—"},
        {"7", "8", "9", "X"}, {"DEL", "0", "=", "÷"}
    };
    CLAY(CLAY_ID("GridOuterBox"), {
        .layout = { .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                    .childGap = 8, .layoutDirection = CLAY_TOP_TO_BOTTOM }
    }) {
        for (int row = 0; row < 4; ++row) {
            CLAY(CLAY_ID(std::to_string(row).c_str()), {
                .layout = { .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                            .childGap = 8, .layoutDirection = CLAY_LEFT_TO_RIGHT }
            }) {
                for (int col = 0; col < 4; ++col) {
                    const char* label = gridButtons[row][col];
                    const bool isOperator = col == 3 || (row == 3 && (col == 0 || col == 2));
                    const bool hovered = Clay_Hovered();
                    const Clay_Color color = isOperator ? Colour_Button_Operation : Colour_Button;
                    CLAY(CLAY_ID(label), { .layout = { .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_GROW() },
                        .childAlignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                        }, .backgroundColor = hovered ? Colour_Button_Hover : color,
                        .cornerRadius = CLAY_CORNER_RADIUS(24) }) {
                        if ((hovered && IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) || IsKeyPressedForButton(label)) HandleButtonInput(label);
                        CLAY_TEXT({ label, static_cast<int32_t>(strlen(label)) }, CLAY_TEXT_CONFIG({
                            .fontId = static_cast<uint16_t>(fontId), .fontSize = strcmp(label, "DEL") == 0 ? 20 : 36,
                            .textColor = { 0, 0, 0, 255 } }));
                    }
                }
            }
        }
    }
}

int main() {
    InitWindow(400, 600, "impcalc");
    SetTargetFPS(60);
    const uint64_t minMemorySize = Clay_MinMemorySize();
    const Clay_Arena clayMemory = Clay_CreateArenaWithCapacityAndMemory(minMemorySize, malloc(minMemorySize));
    Clay_Initialize(clayMemory, {.width = static_cast<float>(GetScreenWidth()), .height = static_cast<float>(GetScreenHeight())}, {.errorHandlerFunction = [](Clay_ErrorData e){}} );
    while (!WindowShouldClose()) {
        auto [x, y] = GetMousePosition();
        Clay_SetPointerState({x, y}, IsMouseButtonDown(MOUSE_BUTTON_LEFT));
        Clay_SetLayoutDimensions({.width = static_cast<float>(GetScreenWidth()), .height = static_cast<float>(GetScreenHeight())});
        // Global key capture engine updates
        for (const char* checkTokens[] = {"1","2","3","+","4","5","6","—","7","8","9","X","DEL","0","=","÷"}; const char* t : checkTokens) {
            if (IsKeyPressedForButton(t)) {
                HandleButtonInput(t);}
        Clay_BeginLayout();
        CLAY_START_ELEMENT(CLAY_ID("Container"), {
            .layout = {
                .sizing = { .width = CLAY_SIZING_GROW(0), .height = CLAY_SIZING_GROW(0) },
                .padding = CLAY_PADDING_ALL(16),
                .childGap = 16,
                .layoutDirection = CLAY_TOP_TO_BOTTOM
            },
            .backgroundColor = colour_BG
        });{
            uint32_t fontId = 0;
            // 1. Title Header Bar Layout
            CLAY(CLAY_ID("HeaderBar"), {
                .layout = {
                    .layoutDirection = CLAY_LAYOUT_DIRECTION_LEFT_TO_RIGHT,
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_FIXED(24) },
                    .alignment = { .x = CLAY_ALIGN_X_SPACE_BETWEEN, .y = CLAY_ALIGN_Y_CENTER }}
            }) {
                CLAY_TEXT(Clay_ParseString("impcalC"), CLAY_TEXT_CONFIG({.fontId = fontId, .fontSize = 28, .textColor = {255,255,255,255}}));
                CLAY_TEXT(Clay_ParseString("v1.1"), CLAY_TEXT_CONFIG({.fontId = fontId, .fontSize = 12, .textColor = {255,255,255,200}}));}
            // 2. Dynamic Calculator Screen Display Layout
            CLAY(CLAY_SID(Clay_ParseString("DisplayScreen")), {
                .layout = {
                    .sizing = { .width = CLAY_SIZING_GROW(), .height = CLAY_SIZING_FIXED(100) },
                    .alignment = { .x = CLAY_ALIGN_X_CENTER, .y = CLAY_ALIGN_Y_CENTER },
                    .padding = CLAY_PADDING_ALL(12)
                },
                .backgroundColor = Colour_Display_BG,
                .cornerRadius = CLAY_CORNER_RADIUS(24)
            }) {
                CLAY_TEXT(
                    { displayBuffer.c_str(), static_cast<int32_t>(displayBuffer.size()) },
                    CLAY_TEXT_CONFIG({
                        .fontId = fontId,
                        .fontSize = (displayBuffer.length() > 10) ? 24 : 40,
                        .textColor = { 0, 0, 0, 255 } // Black text color
                    })
                );}
            // SECTION 3: DRAW THE BUTTONS GRID
            RenderCalculatorGrid(fontId);}
        Clay_RenderCommandArray renderCommands = Clay_EndLayout();
        // SECTION 4: THE RAYLIB CANVAS GRAPHICS
        BeginDrawing();
        ClearBackground(RAYWHITE);
        Clay_Raylib_Render(renderCommands);
        EndDrawing();}
    // SECTION 5: WINDOW CLEANUP
    CloseWindow();
    return 0;}
