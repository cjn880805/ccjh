// shiye.c ֪��ʦү
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity_tanyouji);
virtual void create()
{
	
	set_name("̷����", "tan youji" );
	set("title", "֪��ʦү");
	set("gender", "����");
	set("age", 57);
	set("icon", old_man2);

	set("combat_exp", 30000);
	set_skill("unarmed", 50);
	set_skill("dodge", 60);
	set_temp("apply/attack",  20);
	set_temp("apply/defense", 20);
	set_temp("apply/damage",  20);
	set("shen_type", 1);

	set_inquiry("�л���","��С��,����ô֪����ϲ���Խл���!");
	
	carry_object("cloth")->wear();

/*
}
	
string ask_me()
{
	if ((int)this_player()->query_temp("marks/��"))
	{
		say("��С�ӣ�����ô֪����ϲ���Խл�����\n");
		command("lick");
		say("��Ȼ���ҳ���ʳ�ѣ��Ҿ͸�����ɡ�����������\n");
		command("whisper " + this_player()->query("id") + " ��ȥ������ȫ�۵µ��ϰ壬ֻҪ���������ҽ���ȥ�ģ����ͻ�...");
		this_player()->delete_temp("marks/��");
		this_player()->set_temp("marks/��2", 1);
		return "������....��....�Ǹ������ܺ�....\n";
	}
	else if((int)this_player()->query_temp("marks/��2"))
		return "���Ǹ��㽭�ˣ�Ҳû������ô���£�\n";
	else
		return "����˿��ż������\n";
}
*/
}
NPC_END;