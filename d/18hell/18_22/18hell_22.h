//18hell_22.h
//ʮ�˵�����ʮ�˲㰢�ǵ���BOSS����

ROOM_BEGIN(CR18hell_22);

virtual void create()			//Call it when Room Create
{
	set_name("��������");
	
	add_npc("linglan");
	add_npc("diyu_shizhe22");

};

virtual int do_look(CChar * me)
{
	say("������ͬ��״�����š���������ǽ����ͤ��¶��Զ�����Ҳ��У�������������ʯ�����϶��£�ʯ�������Ź���վ�ں��������������ڿ�����", me);
	say("���������ͺ���Ÿ��ִ�С���������������ܲ�������һ���ͽ����������룬ֱ���������������˱����ڽ����£�һ�����ſ�Ѫ����ҧ�����˲��ھ����ϣ����۲�ͣ���������˵Ķ���", me);
	say("�����ɳ�����������˱����俴Ѻ�����ڲ�ͣ�ر�ɳ���Աߣ�����������׷�Ϻͱ޴��ﷸ��ǿ���ﷸ����ϵ��ܿࡣ", me);
	SendMenu(me);
	return 1;
}

ROOM_END;