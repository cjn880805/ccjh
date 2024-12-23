//yaopu.h

//Sample for room: ҩ��
//coded by Fisho
//data: 2000-11-2

ROOM_BEGIN(CRYangZhou_yaopu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ҩ��");

	//add npcs into the room
	add_npc("pub_ping");
	add_npc("pub_huoji");
	
	add_door("���ݶ���", "���ݶ���", "����ҩ��");

	set("long", "����һ��ҩ�̣�һ��ŨŨ��ҩζ���㼸����Ϣ�����Ǵ�ҩ���ϵļ��ٸ�С������ɢ�������ġ���ҽƽһָ���ڲ輸�ԣ����Ժ��Ų裬��Ҳ������һ�ۡ�һ��С���վ�ڹ�̨���к��Ź˿͡���̨������һ�ŷ��ƵĹ��(guanggao)��" );
/*****************************************************
	set("item_desc", ([
		"guanggao" : "�����������ҩƷ��
��ҩ��\t��ʮ������
�޳������һ�����ҩʦ���䣬������ǣ�
�쾦�����ΰٶ�����Ч������
������ҩ���ϰ����顣\n",
	]));
//	set("item_desc", ([
//		"guanggao" : "�����ϰ�ƽһָ�����ҩδ�飬������ͣӪҵ��\n",
//	]));
	set("objects", ([
		__DIR__"npc/ping" : 1,
		__DIR__"npc/huoji" : 1,
	]));
	set("exits", ([
		"south" : __DIR__"dongdajie2",
	]));
//	
********************************************/
};


ROOM_END;
