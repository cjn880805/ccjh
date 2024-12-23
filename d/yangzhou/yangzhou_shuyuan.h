//shuyuan.h

//Sample for room: ��Ժ
//coded by Fisho
//data: 2000-11-1

ROOM_BEGIN(CRYangZhou_shuyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ժ");

	//add npcs into the room
	add_npc("pub_zhu");/////////////////////////

	add_door("���ݶ���", "���ݶ���", "������Ժ");

	set("no_fight", 1);
	set("no_steal", 1);
	set("no_beg",1);
/*****************************************************
	set("item_desc", ([ 
		"xuegui": "
		�ս����������տ���Ŀ��ҳ��
		ͨ��ʱ�������ζ�����ʫ����
		���������ʣ���ΰ�ʱ���ꡣ
		ҹ���Խ���������Ҫ������

	��ѧ���ѧ����ʮ����\n",
		"board": "
       ����Ժ��ʥ�϶�ּ�Լ��������ѧλ��
  0       ��ä
 10       ͯ��
 20       ���
 30       ����
 40       ��Ԫ
 50       ��ʿ
 60       ��Ԫ
 70       ��ʿ
 80       ̽��
 90       ����
100       ״Ԫ
110       ����Ժʿ
120       ����˶ʿ
130       ���ֲ�ʿ
140       ����Ժ����
150       ����ʿ
160       ѧʿ
170       �ڸ��ѧʿ
180       �ڸ��׸�
190       ��ѧ����ʦ
200       ʥ��\n" 
	]));
	set("exits", ([ 
		"up"    : __DIR__"shuyuan2",
		"south" : __DIR__"dongdajie1",
	]));
	set("objects", ([ 
		__DIR__"npc/zhu" : 1,
	]));
********************************************/
};


ROOM_END;
