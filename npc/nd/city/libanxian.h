// libanxian.h�������
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity_banxian);

virtual void create()
{
        set_name("�����", "li banxian" );
        set("long", "������Ǹ��׷�ͯ�յ����ˣ��������ˣ��������������[����ʦ]�������\n");
        set("nickname", "�����ͷ");
        set("attitude", "peaceful");
        set("combat_exp",600000);
        set("icon", old_man1);
        
        set("str",23);
        set("per",10);
        set("int",27);
        set("dex",17);
        set("con",17);
        
        set("hp", 6000);
	set("max_hp", 6000);
	set("mp", 2000);
	set("max_mp", 2000);
	set("mp_factor", 100);
        
        set_skill("unarmed", 200);
        set_skill("parry", 200);
        set_skill("dodge", 200);
        set_skill("force",200);
        set_skill("chanchu_bufa",200);
        set_skill("hamagong",200);
        set_skill("shexing_diaoshou",200);
        set_skill("lingshe_zhangfa",200);
        set_skill("staff",200);

        map_skill("dodge", "chanchu_bufa");
        map_skill("force", "hamagong");
        map_skill("parry", "lingshe_zhangfa");
        map_skill("unarmed", "shexing_diaoshou");
        map_skill("staff", "lingshe_zhangfa");
        
//      set_inquiry ("����ʦ��¼" ,"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
        set_inquiry("��ʦ", "������ڱ���ʦ���˰ɡ�");
        set_inquiry("��ʦ��¼", "Ҫ������ǰ�����й�һ����ʦʦ�ŵĻ������ʦ���ɲ�Ը����������Ĺ���");
//                "����ʦ"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
//              "����¼"          :"���Ҷ����ˣ��������ܸ������ʦ��¼(jian ��ʦ��¼)��\n",
  
/*
}
int accept_fight(object me)
{
        command("say �����˵���㻹������ҹ��С�");
        return 0;
}
void init()
{
        add_action("do_jian","jian");
}

int do_jian(string arg)
{
        object me;
        mapping my_skl;
        string *skl_name;
        int i,*level;
        me= this_player();
        if (arg != "��ʦ��¼") 
                return notify_fail("��Ҫ��ʲô��\n");
        if (me->query("betrayer",) < 1) 
                return notify_fail("���ѹ�ʦô��\n");
       if ( me->query("banshi") > 2)
           {
               message_vision("�����ʦ�����Ѿ�����3���ˣ���\n", this_object(), me);
                   return 1;
           }

        my_skl=me->query_skills();
        if(mapp(my_skl)) {
        		skl_name = keys(my_skl);
        		level=values(my_skl);
        		for (i=0;i<sizeof(skl_name);i++)
{
if (level[i]>1)
        		me->set_skill(skl_name[i],level[i]-1);
}
                  }
        message_vision(MAG"$N�����˵��ϣ���ʼ��ڱ���ʦ�ŵ����£����ѽ��������ڡ�����\n\n"NOR,me);
        me->set("combat_exp", me->query("combat_exp") - me->query("combat_exp") /10);
        me->add("betrayer",-1);
        me->add("banshi", 1);
//        me->add("banshi",1);
        me->set("title","��ͨ����");
        me->set("class","0");
        me->delete("family");
        me->delete("party");
        me->start_busy(2);
        me->set("score",me->query("score") - me->query("score") /10);
        return 1;
}
*/

}
NPC_END;
