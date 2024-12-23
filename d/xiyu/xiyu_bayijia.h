//bayijia.h

//Sample for room: ������
//coded by zwb
//data: 2000-11-21

//Note: these two headers must be include
//use macro XIYU_BEGIN(room_name) to declare room
//and use macro XIYU_END end declare
XIYU_BEGIN(CRXiYu_bayijia);

//room_name must use "CR-" begin since it belongs room class
//Example: Xiang Yang City named "CRXiangYangCity"

//under, we will custom our room

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add boxes into the room
	//box container some items
	//parames are box's position
	CBox * box = Add_Box();
	box->add_object("coin", 600);	//put 100 coind into box
	box->set_name( "������");		//set box's name
	//if you want to lock this box, use under codes
//  box->Locked("����", 100);		//����Ϊ��ʾ״̬��100Ϊ���Ľ�ʵ�̶ȡ�����ʹ��ħ���򿪡�

	//add exits for room
	//the first param: door id
	//from the second to the fifth params: position of door
	//the sixth param: to next room
	//the seventh param: to next door id of next room
	add_door("С��", "����С��", "���������");

};



XIYU_END;
//last, register the room into ../server/RoomSetup.cpp