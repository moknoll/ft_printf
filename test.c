/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:52:15 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 11:15:10 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>

int main() {
    int a = 42;
    int *ptr = &a;

    printf("The adress is %p, the value is %d", ptr, *ptr);

    return 0;
}
