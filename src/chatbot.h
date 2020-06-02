#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation

	// destructor 1st Rule of 5 
	~ChatBot();                    

    //// STUDENT CODE

	// Copy Constructor - 2nd Rule of 5 
    ChatBot(const ChatBot& source);
    // Copy Assignment Operator - 3rd Rule of 5 
    ChatBot& operator=(const ChatBot& source);
    // Move Constructor - 4th Rule of 5 
    ChatBot(ChatBot&& source);
    // Move Assignment Operator - 5th Rule of 5 
    ChatBot& operator=(ChatBot&& source);

	//// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif 
