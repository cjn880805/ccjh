//pub_yuguangqi.h ��������ʹ�����

NPC_BEGIN(CNpub_yuguangqi);

virtual void create()
{
	set_name("�����","sun chenxian");

	set("icon", officer);
	set("title", "��������ʹ");

	set("gender", "����");
	set("age", 48);
	set("per",26);
	set("long","������Ϊ��������ʹ���縺�����������Σ��Ը�ȴʮ�ֵ�С���£���ϲ��ɫ��");
	set("no_huan",1);

};

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(me->is_busy())
		return notify_fail("����һ��������û�����");
	
	if(me->query("zhang/renwu5")==2 && !me->query("zhang/renwu5_ok") && !me->query_temp("zhang/renwu5_24")
		&& me->query_temp("zhang/renwu5_240"))
	{
		if(!userp(ob) && ob->query("per")>25 && ob->query("age")<24 && ob->query("age")>12 &&
			EQUALSTR(ob->querystr("gender"), "����"))
		{
			tell_object(me,"\n$HIC������ֲ����̣�˫���£���������ϣ��������Ŵ��˻����������¹ٰ����Ժ��¹ٽ����Ŵ���������հ����\n");
			me->set_temp("zhang/renwu5_24",1);
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
