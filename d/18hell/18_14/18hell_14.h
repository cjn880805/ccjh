//18hell_14.h
//ʮ�˵�����ʮ�㺮������BOSS����

//coded by sound
//data: 2001-10-21

ROOM_BEGIN(CR18hell_14);

virtual void create()			//Call it when Room Create
{
	set_name("��������");
	
	add_npc("bingliang_bohe");
	add_npc("diyu_shizhe14");

};

virtual int do_look(CChar * me)
{
	say("���У���ɽѩ�أ������Х��Զ���ص���Χ�ǻ�����������ѩ�������ε�Χ�Ǵ����������ѩ���ͺ��磬��״����ı����ϣ��������������������ò�����", me);
	say("�Ժ󣬱�����ı�ɽ���������������ѩ��֮�У��еĳ������壬�е�ֻ�����ã���������ֱ����£����ǡ�·�ж����ǣ�����ʬ�Ǻ����������ǳֵ��ٰ����䱸ɭ�ϣ�Ψ�б�ɽ��������΢����˸�� ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;