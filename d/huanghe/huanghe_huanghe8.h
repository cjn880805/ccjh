//huanghe8.h

//Sample for room: �ƺ��뺣��
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe8);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ��뺣��");

	add_npc("pub_tangseng");
	
	add_door("�ƺӰ���7", "�ƺӰ���7", "�ƺ��뺣��");

	set("long","�ƺ�������ظ�ԭ��������ԭ������ƽԭ���ܳ�һ����Ű�����������󺣡�");
	

/*****************************************************
	set("exits", ([
		"southwest" : __DIR__"huanghe7",
	]));
********************************************/
};


CHANGAN_END;
