// yufu.c ���

//code by sound
//2001-07-12

NPC_BEGIN(CNxiakedao_yufu);

virtual void create()
{
	set_name("���", "yu fu");
	set("icon", young_man3);
	set("gender", "����" );
	set("age", 22);
	create_family("���͵�", 2, "����");
	set_inquiry("���͵�","��ô������ȥ���ҵ�ʦ�������ҵ��ǵط���̫���ף�ֻ��ϧ�ҵĴ����ˡ���������");
}
/*
int accept_object(object me, object ob)
{
	object ling1;
	object ling2;
	if (ob->query("money_id") && ob->value() >= 50000)
	tell_object(me, "���Ц��˵�����ðɣ���Ȼ����Ե�ˣ��Ҿ�������������ɡ�\n");

	else
	{
		tell_object(me,"���������ü��˵�������Ҳ���ҪǮ�ƣ���\n");
		return 0;
	}

        ling1=new("/d/xiakedao/obj/tongpai1");
        ling1->set_temp("own", (string)me->query("id"));
        ling1->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        ling2=new("/d/xiakedao/obj/tongpai2");
        ling2->set_temp("own", (string)me->query("id"));
        ling2->move(me);
        message_vision("����$Nһ��ͭ�����ơ�\n", me);

        return 1;
}
*/
NPC_END;