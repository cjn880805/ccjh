// shizhongyu.c ʯ����
//code by sound
//date:2001-07-12

NPC_BEGIN(CNxiakedao_shizhongyu);

virtual void create()
{
        set_name("ʯ�м�", "shi zhongyu");
        set("gender", "����");
        set("age", 20);
        set("str", 15);
        set("int", 45);
        set("con", 18);
        set("dex", 20);
        set("per", 30);
        set("long", 
        	"����һ�����ṫ�ӣ���Լ��ʮ�����꣬��������֮�£�ɫ�紺��֮�����������ã�\n"
		"ü��ī�������������������ﲨ����ŭ��ʱЦ�����Ӷ����顣\n");
	set("icon",young_man4);
        set("combat_exp", 30000);
        set("shen_type", 1);
        set("attitude", "peaceful");

        set_skill("unarmed", 30);
        set_skill("force", 30);
        set_skill("blade", 20);
        set_skill("dodge", 30);
        set_skill("parry", 30);
        set_skill("literate",100);

        set_skill("wuhuduanmendao", 50);
        set_temp("apply/attack", 30);
        set_temp("apply/defense", 30);
        set_temp("apply/armor", 5);
        set_temp("apply/damage", 10);
        map_skill("blade", "wuhuduanmendao");

        set("mp", 200);
        set("max_mp", 200);
        set("mp_factor", 20);
        
        set_inquiry("���͵�","��Ȫ�ݸ�����һ��С����");
        set_inquiry("ʯ����","�����ҵ����ֵܣ������������͵�����������ɱ����˴������̻��ѽ��");
        set_inquiry("����", "�Һþ�û�������ˣ���֪����������ô���ˡ�");
        set_inquiry("���Ʒ�����","������������Ե����͵�ѧ�书ѽ��");

	set("chat_chance", 8);

        carry_object("gangdao")->wield();
        carry_object("cloth")->wear();
//        add_money("gold",1);
}

virtual char * chat_msg()
{
	switch(random(4))
	{
	case 0:
		return "ʯ�м�˵��: ������������ѽ���Һ�����ѽ��";
	case 1:
		return "ʯ�м�̾��: Ҳ��֪���ҵĶ�����ô���ˡ�";
	case 2:
		return "ʯ�м�˵��: ��������Ǻö���...";
	case 3:
		return "ʯ�м�˵��: ����˭�ܰ���ɱ���������ͷ���ֵ���лл���ˣ�";
	}
	return 0;
}
/*
void init()
{
        object ob;
        ob = this_player();
        ::init();
        remove_call_out("greeting");
        call_out("greeting", 1, ob);
}

void greeting(object ob)
{
        int change=0;
        if( !ob || environment(ob) != environment() )
                return;
        message_vision( "\nʯ���������Ц���������ڿ������ҵ������ˡ�\n",this_object());
}

void die()
{
        say("\nʯ����˵�����һ��и���Ըû�ˣ�ϣ�����ܰ����չ˶�����\n");

        message_vision("ʯ�����Ŷ��������֣����ˣ�\n", this_object());
        ::die();
}

int accept_object(object who, object ob)
{
        object obn;

        if( !who || environment(who) != environment() )
                return 0;
        if ( !objectp(ob) )
                return 0;
        if ( !present(ob, who) )
                return notify_fail("��û�����������");

        if ( (string)ob->query("id") == "shou pa")
        {
                remove_call_out("destroy");
                call_out("destroy", 1, who, ob);

                message_vision("\nʯ����ж�������ӭ��������֪����������Ϣ�ˣ�\n",who);
                obn = new("/d/xiakedao/obj/shane-bu");
                obn->move(who);
                return 1;
        }
}

void destroy(object me, object ob)
{
        destruct(ob);
        return;
}
*/
NPC_END;