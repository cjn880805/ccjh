//jianchuankou.h

//Sample for room: ����ǽ���ɽ��
//coded by zouwenbin
//data: 2000-11-24

RESIDENT_BEGIN(CRDaLiNorth_jianchuankou);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ǽ���ɽ��");

	set("resident", "������");

	//add npcs into the room
	add_npc("pub_wujiang");
	add_npc("pub_bing");

	add_door("����ǽ�����", "����ǽ�����", "����ǽ���ɽ��");
	add_door("����Ǵ���ɽ·", "����Ǵ���ɽ·", "����ǽ���ɽ��");

	set("long", "�����ǲ�ɽ��´��һ�����ĳ��򡣴˵�����ɽ�ڣ����߳�ɽ����������������·���У�Ψ�д���������ɽ������Ǵ�����������ľ���Ҫ�壬������ڴ����е�¥����������פ�����йٱ������վ��Ѳ�ߣ��̲�������ˡ�");
	
};

RESIDENT_END;
