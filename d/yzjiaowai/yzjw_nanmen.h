//yzjw_nanmen.h

//Sample for room:  ��������
//coded by zwb
//data: 2000-11-20

ROOM_BEGIN(CRYZJW_nanmen);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	add_npc("pub_bing");         //add by zdn 2001-07-16
	add_npc("pub_weiyangyu");
	add_npc("pub_lanlanglang");

	add_door("��������","��������","��������");
	add_door("���ݲݵ�7","���ݲݵ�7","��������");
	add_door("���ݲݵ�8","���ݲݵ�8","��������");


	set("long","�����ϳ��ţ���ǽ�������˹���ƣ������˻������̸��и�ҵ�Ĺ�棬�ٸ��ĸ�ʾ(gaoshi)��˲�̫��Ŀ���ٱ��Ǳ������Ļ���Ц�����������ƺ����Ǻ�������ִ�ڡ�һ����ֱ����ʯ�������ϱ��������졣");

};


ROOM_END;
