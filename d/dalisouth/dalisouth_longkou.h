//longkou.h

//Sample for room: ���ڳ�
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaLisouth_longkou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ڳ�");

	set("resident", "ϲ��");

	//add npcs into the room
	add_npc("pub_bing");
	add_npc("pub_bing");
	
	add_door("�������������", "�������������", "��������ڳ�");

	set("long", "�����ѵ������Ͻ��ˣ����ڳ�����Ԫ�������ٽ�·��������ϲ������ǧ�����������ϡ�٣��˵�����������Ĳ�Զ��ȴҲ���ϲ�����Ҫ�ؿ�֮һ�ˣ��Ǻ��Ϸ��ٹ�ͨ�̵Ŀڰ����ɴ˱�ȥ��ʮ���Ｔ��ϲ�ݳǣ��ϱ���Ԫ���в���̨�Ĵ�ׯ������ٸ��ڴ���Щפ����" );
	
};


RESIDENT_END;
