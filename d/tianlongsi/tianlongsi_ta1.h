//ta1.h



//Sample for room:  ������������1

//coded by zouwenbin

//data: 2000-11-30



//Note: these two headers must be include

//use macro ROOM_BEGIN(room_name) to declare room

//and use macro ROOM_END end declare

ROOM_BEGIN(CRTianLongSi_ta1);



virtual void create()			//Call it when Room Create

{

	//set name of our room

	set_name( "������������1");

	add_door("����������", "����������", "������������1");

	add_door("�������޾���", "�������޾���", "������������1");

	add_door("���������Ҹ�", "���������Ҹ�", "������������1");

	add_door("�����³�ʥ����", "�����³�ʥ����", "������������1");



	set("long","����������������ߵ�һ������Լ������ߣ�����ʮ�������ഫ����ԭ��������һ��ǰ����ɮ�������ӣ����ڵ���鳼������߱�ϵµ۴�λ�������´���ʱ�������Ӳ�֪�����ʧ���ˣ���Ҳ��Ϊ�������������ֵ��ĸ����¡��������Ҳ��֪�����Ǽ١�");




};


ROOM_END;
