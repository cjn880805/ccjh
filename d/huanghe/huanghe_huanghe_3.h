//huanghe_3.h

//Sample for room: �ƺ�3
//coded by zouwenbin
//data: 2000-11-27

CHANGAN_BEGIN(CRHuangHe_huanghe_3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�ƺ�3");
	
	add_npc("pub_daoke");       //add by zdn 2001-07-14

	add_door("�ƺ�2", "�ƺ�2", "�ƺ�3");
	add_door("�ƺ�����", "�ƺ�����", "�ƺ�3");

	set("long","��ˮ���˹��ˣ���Դ�ھ�Ȫ�����ĺ�ˮ�����³Ǻ��������������ˮ��ȥ���𽥼�ǿ��Ю����ǧ��ֵĸ�ԭ��ɳ���Ʋ��ɵ��������ϱ�ȥ�����ڴ˴�ˮ���ļ���������������֬�ᡣ�������µĻƺӴ����㼴���ڴˡ�");
    

/*****************************************************
	set("exits", ([
		"east" : __DIR__"huanghe_2",
		"west" : __DIR__"yongdeng",
	]));
********************************************/
};


CHANGAN_END;
