//dahai.h

//Sample for room: Ȫ�ݴ�
//coded by Fisho
//data: 2000-11-4

RESIDENT_BEGIN(CRQuanZhou_dahai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "Ȫ�ݴ�");
	add_item("baiguo");

	set("resident", "���");


	add_door("Ȫ�ݺ���", "Ȫ�ݺ���", "Ȫ�ݴ�");
	add_door("Ȫ�������", "Ȫ�������", "Ȫ�ݴ�");

	set("long", "��������ãã��֮�С��㼫ĿԶ����ֻ������һ�ߣ���Χ�����ڵ㶼û�С�����ֻ�к��˵��Ĵ�����" );
	
	
/*****************************************************

********************************************/
};


RESIDENT_END;
