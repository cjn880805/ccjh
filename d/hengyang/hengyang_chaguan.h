//chaguan.h

//Sample for room: �������
//coded by Fisho
//data: 2000-11-4

ROOM_BEGIN(CRHengYang_chaguan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�������");


	add_npc("pub_chaboshi");
        add_npc("hengshan1_moju");

	add_door("������", "������", "�������");

 	set("resource/water", 1);
/*****************************************************
	set("long", "��һ�߽��������ŵ�һ�ɲ���������Ƣ������Ϊ֮һˬ�����Ű�����һ��
�ſ��������˿��ˣ������̸Ц����ͷ�Ӷ�����Ҫ����������ƹʺ�ҥ�ԣ�
�����Ǹ������ڡ�
 " );
	set("exits", ([
		"north" : __DIR__"hengyang",
	]));
	set("objects", ([
		__DIR__"npc/chaboshi" : 1,
	]));

********************************************/
};


ROOM_END;
