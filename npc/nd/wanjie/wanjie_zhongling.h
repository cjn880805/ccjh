// zhongling.c

//code by sound
//date:2001-07-12

NPC_BEGIN(CNwanjie_zhongling);

virtual void create()
{
        set_name("����", "zhong ling");
        set("gender", "Ů��" );
        set("age", 15);
        set("str", 16);
        set("con", 24);
        set("dex", 11);
        set("per", 27);
        set("int", 24);
        set("icon",young_woman2);

        set("chat_chance", 1);

	set_inquiry("����"," �θ���أ������Ķ��� ");
	set_inquiry("����"," �Ҿ������鰡�� ");
	set_inquiry("�ʱ���"," �ʱ��������衣 ");
	set_inquiry("��ǧ��"," ��������ҵ��� ");
	set_inquiry("����"," ��������ٹȡ� ");
	set_inquiry("ľ����"," ľ���屻���ں����ʯ�����ȥ������ ");

        set("attitude", "friendly");

        set("max_mp", 200);
        set("mp", 200);
        set("mp_factor", 10);

        set("combat_exp", 3500);

        set_skill("finger", 60);
        set_skill("parry", 40);
        set_skill("dodge", 50);
        set_skill("sword", 30);
        set_skill("force", 50);
        set_skill("sun_finger",40);

        map_skill("finger", "sun_finger");
        map_skill("parry", "sun_finger");

//	carry_object("moon-dress")->wear();
//	carry_object("shoes")->wear();
//	carry_object("xiu-scarf")->wear();
}

virtual char *chat_msg(CChar * player)
{
	return "�����������������Ҫ���ҵ�������������ͺ��ˡ���";
}

/*
void init()
{
        object ob;
        ::init();
        if( interactive(ob = this_player()) ) {
        message_vision("�����$N˵������ȥ��ľ��㣬ľ��㱻���ں����ʯ���\n",ob);
        }
}

int accept_object(object who, object ob)
{
        object *inv, sh;
        int i;

        inv = all_inventory(this_object());

        if (ob->name() == "������") {
            tell_object(who,"����˵����лл������һ�����������\n");
            tell_object(who,"����˵�����´����������ʱ�����������Ѿ��ؼ��ˡ�\n");
            if(!sizeof(inv) )
                for ( i=0; i< sizeof(inv); i++ )
                    if ( inv[i]->name() == "�廨Ь" ) {
                        destruct(inv[i]);
                        tell_object("who, ��������һ˫�廨Ь��\n");
                        sh = new("/t/wanjiegu/npc/obj/shoes2");
                        tell_object(who, "����˵���������ҵ�һ˫�廨Ь���������������\n");
                        sh->move(who);
                        return 1;
                    }
            return 1;
        }
        return 0;
}

void die()
{
        int i;
        object killer;

        if(objectp(killer = query_temp("last_damage_from")))
            killer->set("marks/murder_zhongling", 1);
        message_vision("����������˵����ԭ�����������һ��ģ�\n", killer);

        ::die();
}
*/
NPC_END;