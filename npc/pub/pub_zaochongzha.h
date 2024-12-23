//zaochongzha.h
//code by zwb
//12-15

NPC_BEGIN(CNpub_zaochongzha);

virtual void create()
{
	set_name("�Գ���","zhao congzha");

	set("icon", officer);
	set("title", "��������");

	set("gender", "����");
	set("age", 48);
	set("long","���˴������ް���Ǯׯ�ſ������߶����ƺ�����ʲô�Ѵ���");

	add_money(3);
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	say("�Գ�������ͨ�죬�о������������ֵ�һ�����������뵽���ռ���ȴ�������´�������", me);
	SendMenu(me);
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("����һ��������û�����");
	
	if ( EQUALSTR(ob->querystr("id"), "coin") && ob->query("value") >=5000 )
	{
		if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_22"))
		{
			switch(me->query_temp("zhang/renwu5_220"))
			{
			case 0:
				tell_object(me,"\n$HIC�Գ�������˫�֣��������������򲻿ɡ����۸����Ǻ��Ļ��ߴ��⣬����ӳ�͢Ҫְ�����򲻿ɽ��ջ�¸�������԰ѱ��ġ���\n");
				me->add_temp("zhang/renwu5_220",1);
				return 0;
			case 1:
				tell_object(me,"\n$HIC�������ǰ�����������������ȷ�����󡣴���ֻ�衭����");
				tell_object(me,"$HIC�Գ������ŭ�������������ᣡ��������������������ֻ�ӽ�һ����¸��Ա֮���\n");
				me->add_temp("zhang/renwu5_220",1);
				return 0;
			case 2:
				tell_object(me,"\n$HIC�����һЦ������˵��������������������࣬��ȴ���Ŀ��ż��а�ʮ��ĸ���������Ӷ�����������ɣ�");
				tell_object(me,"$HIC���������ТΪ��,��֮�����������¡���˵���˻�����һ�����̵������Լ���ĸ���Ӷ����˵���ô��");
				tell_object(me,"$HIC�Գ��������������һ��������������ƥ����ˣ���\n");
				tell_object(me,"$HIC�Գ���һ��ãȻ������Ƭ�̣������ߺ죬����֮����̾���������ˣ����ˡ�������ü��ǣ����¾������ˡ���������\n");
				me->delete_temp("zhang/renwu5_220");
				me->set_temp("zhang/renwu5_22",1);
				break;
			}
		
			destruct(ob);
			if(me->query_temp("zhang/renwu5_21") && me->query_temp("zhang/renwu5_22")
				&& me->query_temp("zhang/renwu5_23") && me->query_temp("zhang/renwu5_24"))
			{
				me->set("zhang/renwu5_ok",2);
				me->delete_temp("zhang/renwu5_21");
				me->delete_temp("zhang/renwu5_22");
				me->delete_temp("zhang/renwu5_23");
				me->delete_temp("zhang/renwu5_24");
			}
			return 1;
		}
	}
	return 0;
}
NPC_END;
