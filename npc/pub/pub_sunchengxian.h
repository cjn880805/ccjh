//pub_sunchengxian.h �����������

NPC_BEGIN(CNpub_sunchengxian);

virtual void create()
{
	set_name("�����","sun chenxian");

	set("icon", officer);
	set("title", "������");

	set("gender", "����");
	set("age", 33);
	set("per",16);
	set("long","�����������ɣ������������ļƣ�������Ӫ�����۲�ʱ¶��̰������ɫ��");
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("����һ��������û�����");
	
	if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_23"))
	{
		if (EQUALSTR(ob->querystr("id"), "coin") )
		{
			if(ob->query("value") >=500000 )
			{
				tell_object(me,"\n$HIC����ܴ������ܣ�ϸ�����ˣ��Ͻ��ӹ��ݹ�������Ʊ�������С�");
				tell_object(me,"$HIC��ȴ���ޱ����˵�������ţ���ү��Ǯ�Ҿ������ˣ����ձض�������\n");
				if(me->query_temp("zhang/renwu5_230"))
				{
					me->delete_temp("zhang/renwu5_230");
					tell_object(me,"$HIC����Ц����������������˲��ǲ�����ֻ�ǲ���С����ˡ���");
					tell_object(me,"$HIC�����ȴ��������֮ɫ��������Ц����������������");
					tell_object(me,"$HIC������˵������������Ͷ������ֻ�ǿ�����·���ˣ������ǹ���Ӧ��ë��������һֽ�������ۻ�������Ľ�����������£��������������\n");
				}
				me->set_temp("zhang/renwu5_23",1);
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
			else
			{
				tell_object(me,"\n$HIC�����б��һƳ�ݹ�������Ʊ�ϵ���Ŀ����Ц������������Ϊ��͢��Ա���Ե���������ϰ��£��ǲ�����ȡ��¸�ġ���\n");
				if(!me->query_temp("zhang/renwu5_230"))
					me->set_temp("zhang/renwu5_230",1);
			}
		}
	}
	return 0;
}
NPC_END;
